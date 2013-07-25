// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "log/log.h"
#include "strings/path.h"

int main() {
  // JoinPath
  CHECK_EQ("/this/is/a/path", strings::JoinPath("/this/is/a", "path"));

  // CleanPath
  CHECK_EQ("/this/is/path", strings::CleanPath("/this/is/a//../path"));

  std::cout << "PASS" << std::endl;
  return 0;
}
