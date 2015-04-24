// Copyright 2015
// Author: Christopher Van Arsdale

#ifndef _COMMON_THREAD_THREADPOOL_H__
#define _COMMON_THREAD_THREADPOOL_H__

#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include "common/base/macros.h"

class Closure;

namespace thread {

class ThreadPool {
 public:
  ThreadPool();
  explicit ThreadPool(int workers);
  ThreadPool(int workers, int max_pending);
  ~ThreadPool();

  void StartWorkers();
  void Wait();
  void Add(Closure* closure);
  size_t NumWorkers() const { return workers_.size(); }

  static int NumCores() {
    return std::thread::hardware_concurrency();
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(ThreadPool);
  typedef std::mutex Mutex;
  typedef std::condition_variable CondVar;
  typedef std::unique_lock<Mutex> MutexLock;

  void WaitLocked(MutexLock* lock);
  void RunThread(int id);

  // Synchronization
  Mutex lock_;
  CondVar new_cond_, active_cond_, done_cond_;

  // Internal state
  int max_pending_;
  int active_;
  bool exiting_;

  // Callbacks/threads
  int num_workers_;
  std::queue<Closure*> pending_;
  std::vector<std::thread*> workers_;
};

}  // namespace thread


#endif  // _COMMON_THREAD_THREADPOOL_H__
