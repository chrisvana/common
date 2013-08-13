// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_TIME_H__
#define _COMMON_BASE_TIME_H__

#include "common/base/rdtsc.h"
#include "common/base/types.h"

void SleepForSeconds(double seconds);
int64 GetCurrentTimeMicros();

// TODO(cvanarsdale): Work in progress. We could calibrate the clock cycles
// instead of doing two different timers in one. Maybe not better.
class CycleTimer {
 public:
  CycleTimer()
      : running_(false), start_(0), end_(0), start_ts_(0), end_ts_(0) {
  }
  ~CycleTimer() {}

  // Start/stop
  void Start() {
    running_ = true;
    start_ts_ = GetCurrentTimeMicros();
    start_ = rdtsc();
  }
  void Stop() {
    end_ = rdtsc();
    end_ts_ = GetCurrentTimeMicros();
    running_ = false;
  }

  // Time functions.
  int64 Get() const {
    return (running_ ? rdtsc() : end_) - start_;
  }
  int64 GetMicros() const {
    return (running_ ? GetCurrentTimeMicros() : end_ts_) - start_ts_;
  }
  double GetMillis() const {
    return static_cast<double>(GetMicros()) / 1000;
  }
  double GetSeconds() const {
    return static_cast<double>(GetMicros()) / 1000000;
  }

 private:
  bool running_;
  uint64 start_, end_;  // cycles
  uint64 start_ts_, end_ts_;  // micros
};

#endif  // _COMMON_BASE_TIME_H__
