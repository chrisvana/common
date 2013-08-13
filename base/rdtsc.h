// Copyright 2013
// Author: Christopher Van Arsdale
// Original author: kazutomo (http://www.mcs.anl.gov/~kazutomo/rdtsc.h).
/*  $RCSfile:  $   $Author: kazutomo $
 *  $Revision: 1.6 $  $Date: 2005/04/13 18:49:58 $
 */

#ifndef __RDTSC_H_DEFINED__
#define __RDTSC_H_DEFINED__

#include "common/base/types.h"

#ifdef __i386__

uint64 rdtsc() {
  uint64 x;
  __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
  return x;
}

#elif defined(__x86_64__)

uint64 rdtsc() {
  uint32 hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return (static_cast<uint64>(hi) << 32) | lo;
}

#elif defined(__powerpc__)

uint64 rdtsc(void) {
  uint32 upper, lower, tmp;
  __asm__ volatile(
      "0:                  \n"
      "\tmftbu   %0           \n"
      "\tmftb    %1           \n"
      "\tmftbu   %2           \n"
      "\tcmpw    %2,%0        \n"
      "\tbne     0b         \n"
      : "=r"(upper),"=r"(lower),"=r"(tmp));
  return (static_cast<uint64>(upper) << 32) | lower;
}

#else

#error "No rdtsc() tick counter is available!"

#endif

#endif  // _COMMON_BASE_RDTSC_H_DEFINED__
