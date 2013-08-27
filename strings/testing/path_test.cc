// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/base/init.h"
#include "common/log/log.h"
#include "common/strings/path.h"

int main(int argc, char** argv) {
  InitProgram(&argc, &argv, true);

  // JoinPath
  CHECK_EQ("/this/is/a/path", strings::JoinPath("/this/is/a", "path"));

  // CleanPath
  CHECK_EQ("/this/is/path", strings::CleanPath("/this/is/a//../path"));

  std::cout << "PASS" << std::endl;
  return 0;
}
