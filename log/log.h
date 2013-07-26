// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_LOG_LOG_H__
#define _COMMON_LOG_LOG_H__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <time.h>

class Logger {
 public:
  Logger()
      : init_(false), code_(-1), no_op_(false), line_(0), file_("") {
  }

  Logger(int exit_code)
      : init_(false), code_(exit_code), no_op_(false), line_(0), file_("") {
  }

  Logger(int exit_code, bool no_op)
      : init_(false), code_(exit_code), no_op_(no_op), line_(0), file_("") {
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

  Logger& Init(int line, const char* file) {
    line_ = line;
    file_ = file;
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
    time_t now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    std::cerr << "[" << buf << "] "
              << file_ << "." << line_ << ": " << stream_.str() << std::endl;
    if (code_ >= 0) {
      exit(code_);
    }
  }

  bool init_;
  std::stringstream stream_;
  int code_;
  bool no_op_;
  int line_;
  const char* file_;
};

enum kLogLevel {
  INFO = 0,
  ERROR = 1,
  FATAL = 2
};

inline Logger GetLogger(int level) {
  return Logger(level >= 2 ? 1 : -1);
}

template <typename T1, typename T2>
inline Logger CheckEQ(const T1&x, const T2& y) {
  if (x != y) {
    Logger l(GetLogger(FATAL));
    l.Log("CHECK FAILED: ");
    l.Log(x);
    l.Log(" != ");
    l.Log(y);
    return l;
  }
  return Logger(-1, true /* no op */);
}

#define LOG(x) GetLogger(x).Init(__LINE__, __FILE__)

#define CHECK(x)                                                          \
  (x ? Logger(-1, true) : GetLogger(FATAL).Log("CHECK FAILED: ").Log(#x)) \
  .Init(__LINE__, __FILE__)

#define CHECK_EQ(x, y) CheckEQ(x, y).Init(__LINE__, __FILE__)

#endif  // _COMMON_LOG_LOG_H__
