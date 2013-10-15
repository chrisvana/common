// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_UTIL_SHELL_H_
#define _COMMON_UTIL_SHELL_H_

#include <string>

namespace util {

// Returns -1 on pipe/etc err.
int Execute(const std::string& command);
int Execute(const std::string& command,
            std::string* stdout);
int Execute(const std::string& stdin,
            const std::string& command,
            std::string* stdout);

}  // namespace util

#endif
