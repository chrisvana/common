// Copyright 2013
// Author: Christopher Van Arsdale

#include <iostream>
#include "common/log/log.h"
#include "common/base/init.h"

int main() {
  InitProgram();
  std::cout << *reinterpret_cast<int*>(-1);

  {  // As x goes out of scope, should exit program.
    LOG(INFO) << "HERE";
    Logger x(Logger(0));
    x.Init(10, "myfile");
    x << "PASS";
    // should exit.
  }

  // If we got here, failed to exit.
  std::cout << "FAIL" << std::endl;
  return 1;
}
