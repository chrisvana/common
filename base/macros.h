// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_BASE_MACROS_H__
#define _COMMON_BASE_MACROS_H__

// Borrowed from various sources.
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);   \
  void operator=(const TypeName&)

#endif  // _COMMON_BASE_MACROS_H__
