// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_LOG_LOG_H__
#define _COMMON_LOG_LOG_H__

#include <cstdlib>
#include <iostream>
#include <sstream>

class Logger {
 public:
  Logger()
      : init_(false), code_(-1), no_op_(false) {
  }

  Logger(int exit_code)
    : init_(false), code_(exit_code), no_op_(false) {
  }

  Logger(int exit_code, bool no_op)
      : init_(false), code_(exit_code), no_op_(no_op) {
  }

  Logger(const Logger& other)
    : init_(other.init_),
      code_(other.code_),
      no_op_(other.no_op_) {
    stream_ << other.stream_.rdbuf();
  }

  ~Logger() {
    if (init_ && !no_op_) {
      Execute();
    }
  }

  Logger& Init() {
    init_ = true; return *this;
  }

  template <typename T>
  Logger& operator<<(const T& v) {
    if (!no_op_) {
      Log(v);
    }
    return *this;
  }

  template <typename T>
  Logger& Log(const T& v) {
    stream_ << v;
    return *this;
  }

 private:
  void Execute() {
    std::cerr << stream_.str() << std::endl;
    if (code_ >= 0) {
      exit(code_);
    }
  }

  bool init_;
  std::stringstream stream_;
  int code_;
  bool no_op_;
};

enum kLogLevel {
  INFO = 0,
  ERROR = 1,
  FATAL = 2
};

inline Logger GetLogger(int level) {
  return Logger(level >= 2 ? 1 : 0);
}

template <typename T>
inline Logger CheckEQ(const T&x, const T& y) {
  if (x != y) {
    Logger l(GetLogger(FATAL));
    l.Log(x);
    l.Log(" != ");
    l.Log(y);
    return l;
  }
  return Logger(-1, true /* no op */);
}

#define LOG(x) \
  GetLogger(x).Init()

#define CHECK(x)                                                        \
  (x ? Logger(-1, true) : GetLogger(FATAL).Log("CHECK FAILED: ").Log(#x)).Init()

#define CHECK_EQ(x, y) \
  CheckEQ(x, y).Init()

#endif  // _COMMON_LOG_LOG_H__
