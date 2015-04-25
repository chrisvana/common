// Copyright 2015
// Author: Christopher Van Arsdale

#ifndef _COMMON_THREAD_COUNTER_H__
#define _COMMON_THREAD_COUNTER_H__

#include <condition_variable>
#include <mutex>
#include "common/base/macros.h"
#include "common/log/log.h"

namespace thread {

class Semaphore {
 public:
  Semaphore() : pending_(0) {}
  explicit Semaphore(int n) : pending_(n) {}
  ~Semaphore() {}

  void Decrement() {
    MutexLock l(lock_);
    CHECK_GT(pending_--, 0);
    if (pending_ == 0) {
      cond_.notify_all();
    }
  }

  void Increment() {
    MutexLock l(lock_);
    ++pending_;
  }

  void Wait() {
    MutexLock l(lock_);
    while (pending_ > 0) {
      cond_.wait(l);
    }
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(Semaphore);
  typedef std::mutex Mutex;
  typedef std::condition_variable CondVar;
  typedef std::unique_lock<Mutex> MutexLock;

  Mutex lock_;
  CondVar cond_;
  size_t pending_;
};

class BlockingCounter {
 public:
  explicit BlockingCounter(int n) : sem_(n) {}
  ~BlockingCounter() {}

  void Decrement() { sem_.Decrement(); }
  void Wait() { sem_.Wait(); }

 private:
  DISALLOW_COPY_AND_ASSIGN(BlockingCounter);
  Semaphore sem_;
};

}  // namespace thread

#endif  // _COMMON_THREAD_COUNTER_H__
