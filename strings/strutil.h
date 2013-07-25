// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_STRINGS_STRUTIL_H__
#define _COMMON_STRINGS_STRUTIL_H__

#include <string>
#include <vector>
#include "strings/stringpiece.h"

// Has*
bool HasPrefix(const StringPiece& base, const StringPiece& prefix);
bool HasSuffix(const StringPiece& base, const StringPiece& suffix);

// Split
std::vector<StringPiece> Split(const StringPiece& base,
                               const StringPiece& delim);
std::vector<StringPiece> SplitAllowEmpty(const StringPiece& base,
                                         const StringPiece& delim);
std::vector<StringPiece> Split(const StringPiece& base,
                               const StringPiece& delim,
                               bool allow_empty);

std::vector<std::string> SplitString(const StringPiece& base,
                                     const StringPiece& delim);
std::vector<std::string> SplitStringAllowEmpty(const StringPiece& base,
                                               const StringPiece& delim);
std::vector<std::string> SplitString(const StringPiece& base,
                                     const StringPiece& delim,
                                     bool allow_empty);

// Implementations -------------------------

inline bool HasPrefix(const StringPiece& base, const StringPiece& prefix) {
  return base.starts_with(prefix);
}

inline bool HasSuffix(const StringPiece& base, const StringPiece& suffix) {
  return base.ends_with(suffix);
}

inline std::vector<StringPiece> Split(const StringPiece& base,
                                      const StringPiece& delim) {
  return Split(base, delim, false);
}

inline std::vector<StringPiece> SplitAllowEmpty(const StringPiece& base,
                                                const StringPiece& delim) {
  return Split(base, delim, true);
}

inline std::vector<std::string> SplitString(const StringPiece& base,
                                            const StringPiece& delim) {
  return SplitString(base, delim, false);
}

inline std::vector<std::string> SplitStringAllowEmpty(
    const StringPiece& base,
    const StringPiece& delim) {
  return SplitString(base, delim, true);
}

#endif  // _STRINGS_STRUTIL_H__
