// Copyright 2013
// Author: Christopher Van Arsdale
//
// TODO(cvanarsdale): Look at google-breakpad?

#include <iostream>
#include "common/base/init.h"
#include "common/base/flags.h"
#include "common/log/log.h"

void InitProgram() {
  google::InstallFailureSignalHandler();
  google::InitGoogleLogging("");
}

void InitProgram(int *argc, char*** argv) {
  return InitProgram(argc, argv, true);
}

void InitProgram(int *argc, char*** argv, bool remove_flags) {
  InitProgram(argc, argv, "", remove_flags);
}

void InitProgram(int *argc, char*** argv,
                 const char* usage, bool remove_flags) {
  google::InstallFailureSignalHandler();
  google::SetUsageMessage(usage);
  google::ParseCommandLineFlags(argc, argv, remove_flags);
  google::InitGoogleLogging((*argv)[0]);
}
