// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_INIT_H__
#define _COMMON_BASE_INIT_H__

#include "common/third_party/google/init/googleinit.h"  // REGISTER_MODULE_*

void InitProgram();  // no command line parsing.
void InitProgram(int *argc, char*** argv);  // remove_flag = true.
void InitProgram(int *argc, char*** argv, bool remove_flags);
void InitProgram(int *argc, char*** argv, const char* usage, bool remove_flags);

#endif  // _COMMON_BASE_INIT_H__
