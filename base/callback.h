// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_CALLBACK_H__
#define _COMMON_BASE_CALLBACK_H__

#include "common/base/callback_gen.h"
#include "common/base/macros.h"

class AutoClosureRunner {
 public:
  explicit AutoClosureRunner(Closure* c) : c_(c) {}
  ~AutoClosureRunner() {
    c_->Run();
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(AutoClosureRunner);

  Closure* c_;
};

#endif  // _COMMON_BASE_CALLBACK_H__
