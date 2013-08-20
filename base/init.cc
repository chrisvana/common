// Copyright 2013
// Author: Christopher Van Arsdale
//
// TODO(cvanarsdale): Look at google-breakpad?

#include <iostream>
#include "common/base/init.h"
#include "common/base/flags.h"
#include "common/log/log.h"

void InitProgram(int *argc, char*** argv, bool remove_flags) {
  google::InstallFailureSignalHandler();
  google::ParseCommandLineFlags(argc, argv, remove_flags);
  google::InitGoogleLogging((*argv)[0]);
}
