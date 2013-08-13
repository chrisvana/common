// Copyright 2013
// Author: Christopher Van Arsdale

#include <ctime>
#include <sys/time.h>
#include "common/base/time.h"

namespace time {

void SleepForSeconds(double seconds) {
  if (seconds <= 0) {
    return;
  }
  timespec t;
  t.tv_sec = static_cast<time_t>(seconds);
  t.tv_nsec = (seconds - t.tv_sec) * 1000000000;
  timespec remaining;
  while (nanosleep(&t, &remaining) == -1) {
    t = remaining;
  }
}

int64 GetCurrentTimeMicros() {
  timeval t;
  gettimeofday(&t, NULL);
  return static_cast<int64>(t.tv_sec * 1000000 + t.tv_usec);
}

}  // namespace time
