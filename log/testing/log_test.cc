// Copyright 2013
// Author: Christopher Van Arsdale

#include <iostream>
#include "../log.h"

int main() {
  {  // As x goes out of scope, should exit program.
    Logger x(Logger(0));
    x << "PASS";  // should exit.
  }

  // If we got here, failed to exit.
  std::cout << "FAIL" << std::endl;
  return 1;
}
