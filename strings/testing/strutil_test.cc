// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "log/log.h"
#include "strings/strutil.h"

int main() {
  // HasPrefix
  CHECK(HasPrefix("This is a block", "This"));
  CHECK(!HasPrefix("This", "This is a block"));

  // HasSuffix
  CHECK(HasSuffix("This is a block", "block"));
  CHECK(!HasSuffix("block", "This is a block"));

  std::cout << "PASS" << std::endl;
  return 0;
}
