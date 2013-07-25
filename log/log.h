// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _ENV_LOG_H__
#define _ENV_LOG_H__

#include <cstdlib>
#include <iostream>
#include <sstream>

class Logger {
 public:
  Logger() : invoked_(false), code_(-1) {}
  Logger(int exit_code) : invoked_(false), code_(exit_code) {}
  ~Logger() {
    if (invoked_) {
      Execute();
    }
  }
  Logger(const Logger& other)
    : invoked_(other.invoked_),
      code_(other.code_) {
    stream_ << other.stream_.rdbuf();
  }

  template <typename T>
  Logger& operator<<(const T& v) {
    invoked_ = true;
    stream_ << v; return *this;
  }

 private:
  void Execute() {
    std::cerr << stream_.str() << std::endl;
    if (code_ >= 0) {
      exit(code_);
    }
  }

  bool invoked_;
  std::stringstream stream_;
  int code_;
};

enum kLogLevel {
  INFO = 0,
  ERROR = 1,
  FATAL = 2
};

inline Logger GetLogger(int level) {
  return Logger(level >= 2 ? 1 : 0);
}

#define LOG(x) return GetLogger(x)

#endif  // _ENV_LOG_H__
