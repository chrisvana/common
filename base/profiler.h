// Copyright 2015
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_PROFILER_H__
#define _COMMON_BASE_PROFILER_H__

// Heap functions:
// int IsHeapProfilerRunning();
// void HeapProfilerStop();
// void HeapProfilerDump(const char *reason);
// char* GetHeapProfile();

// CPU functions:
// int ProfilerStart(const char* fname);
// int ProfilerStartWithOptions(const char *fname,
//                              const struct ProfilerOptions *options);
// void ProfilerStop();
// void ProfilerFlush();
// void ProfilerEnable();
// void ProfilerDisable();
// void ProfilerRegisterThread();

#include "common/third_party/google/gperftools/src/gperftools/profiler.h"
#include "common/third_party/google/gperftools/src/gperftools/heap-profiler.h"


#endif  // _COMMON_BASE_PROFILER_H__
