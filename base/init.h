// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_INIT_H__
#define _COMMON_BASE_INIT_H__

void InitProgram();  // no command line parsing.
void InitProgram(int *argc, char*** argv, bool remove_flags);

#endif  // _COMMON_BASE_INIT_H__
