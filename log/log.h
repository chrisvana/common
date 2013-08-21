// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_LOG_LOG_H__
#define _COMMON_LOG_LOG_H__

#include "common/third_party/google/glog/src/glog/logging.h"
#include "common/third_party/google/glog/src/glog/raw_logging.h"

#ifndef LG
#define LG LOG(INFO)
#endif

// Some of the definitions:
//
// LOG(*) << ..., * = INFO, ERROR, WARNING, FATAL, DFATAL
// LOG_EVERY_N(*, 10) << ...
// LOG_IF(*, bool) << ...
// LOG_IF_EVERY_N(*, bool, 10) << ...
// LOG_FIRST_N(*, 10) << ...
//
// DLOG(*) << ...
// DLOG_IF, DLOG_EVERY_N
//
// VLOG(1)
// VLOG_IF(1, bool)
// VLOG_EVERY_N(1, n)
// VLOG_IF_EVERY_N(1, bool, n)
// 
// CHECK, CHECK_EQ, CHECK_NE, CHECK_NOTNULL, CHECK_DOUBLE_EQ, CHECK_NEAR(a,b,d)
// DCHECK, DCHECK_EQ, DCHECK_NE


#endif  // _COMMON_LOG_LOG_H__
