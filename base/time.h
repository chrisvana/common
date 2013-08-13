// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_TIME_H__
#define _COMMON_BASE_TIME_H__

#include "common/base/types.h"

namespace time {

void SleepForSeconds(double seconds);
int64 GetCurrentTimeMicros();

// TODO(cvanarsdale): Cycle timer (platform specific).
class Timer {
 public:
  Timer() : running_(false), start_(0), end_(0) {}
  ~Timer() {}

  // Start/stop
  void Start() { running_ = true; start_ = GetCurrentTimeMicros(); }
  void Stop() { end_ = GetCurrentTimeMicros(); running_ = false; }

  // Time functions.
  int64 GetMicros() const {
    return (running_ ? GetCurrentTimeMicros() : end_) - start;
  }
  double GetMillis() const { return GetMicros() / 1000; }
  double GetSeconds() const {  return GetMicros() / 1000 / 1000; }

 private:
  bool running_;
  int64 start_, end_;
};

}  // namespace time

#endif  // _COMMON_BASE_TIME_H__
