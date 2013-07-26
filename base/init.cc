// Copyright 2013
// Author: Christopher Van Arsdale
//
// TODO(cvanarsdale): Look at google-breakpad.

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "base/init.h"

namespace {
void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}
}

void InitProgram() {
  signal(SIGSEGV, handler);
}
