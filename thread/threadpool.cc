// Copyright 2015
// Author: Christopher Van Arsdale

#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include "common/base/callback.h"
#include "common/log/log.h"
#include "common/thread/threadpool.h"

namespace thread {

ThreadPool::ThreadPool()
    : max_pending_(-1),
      active_(0),
      exiting_(false),
      num_workers_(NumCores()) {
}

ThreadPool::ThreadPool(int workers)
    : max_pending_(-1),
      active_(0),
      exiting_(false),
      num_workers_(workers) {
}

ThreadPool::ThreadPool(int workers, int max_pending)
    : max_pending_(max_pending),
      active_(0),
      exiting_(false),
      num_workers_(workers) {
}

ThreadPool::~ThreadPool() {
  MutexLock l(lock_);

  // Wait for existing operations to finish.
  WaitLocked(&l);
  CHECK_EQ(0, pending_.size());
  CHECK_EQ(0, active_);

  // Shutdown.
  exiting_ = true;
  new_cond_.notify_all();
  l.unlock();
  for (std::thread* t : workers_) {
    t->join();
    delete t;
  }
}

void ThreadPool::StartWorkers() {
  int num_workers = (num_workers_ <= 0 ? NumCores() : num_workers_);

  MutexLock l(lock_);
  if (workers_.empty()) {
    for (int i = 0; i < num_workers; ++i) {
      workers_.push_back(new std::thread(&ThreadPool::RunThread, this, i));
    }
  }
}

void ThreadPool::RunThread(int id) {
  VLOG(2) << "Thread " << id << " starting.";

  // Wait until we have something to work with.
  MutexLock l(lock_);
  while (true) {
    while (pending_.empty() && !exiting_) {
      new_cond_.wait(l);
    }

    // Maybe exit.
    if (exiting_) {
      l.unlock();
      VLOG(2) << "Thread " << id << " exiting.";
      return;
    }

    // Run next closure.
    Closure* to_run = pending_.front();
    pending_.pop();
    ++active_;
    active_cond_.notify_all();
    l.unlock();
    VLOG(5) << "Thread " << id << " running callback " << to_run;
    to_run->Run();
    l.lock();
    --active_;
    done_cond_.notify_all();
  }
}

void ThreadPool::Wait() {
  MutexLock l(lock_);
  WaitLocked(&l);
}

void ThreadPool::WaitLocked(MutexLock* l) {
  while (active_ > 0 || !pending_.empty()) {
    done_cond_.wait(*l);
  }
}

void ThreadPool::Add(Closure* closure) {
  VLOG(5) << "Adding callback " << closure;

  MutexLock l(lock_);
  if (workers_.empty()) {
    l.unlock();
    LOG(FATAL) << "Must call StartWorkers before Add.";
  }
  while (max_pending_ >= 0 && pending_.size() >= max_pending_) {
    active_cond_.wait(l);
  }
  pending_.push(closure);
  new_cond_.notify_one();
}

}  // namespace threadpool
