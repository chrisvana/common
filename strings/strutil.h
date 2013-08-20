// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_STRINGS_STRUTIL_H__
#define _COMMON_STRINGS_STRUTIL_H__

#include <sstream>
#include <string>
#include <vector>
#include "common/strings/stringpiece.h"

namespace strings {

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

// Join
template <class T>
std::string Join(const T& t, const StringPiece& delim) {
  std::stringstream out;
  bool first = true;
  for (const auto& it : t) {
    if (!first) {
      out << delim;
    }
    first = false;
    out << it;
  }
  return out.str();
}

// printf
std::string StringPrintf(const char *format, ...);
void SStringPrintf(std::string* dst, const char* format, ...);
void StringAppendF(std::string* dst, const char* format, ...);

// Replace
std::string Replace(const StringPiece& input,
                    const StringPiece& original,
                    const StringPiece& replace);
std::string ReplaceAll(const StringPiece& input,
                       const StringPiece& original,
                       const StringPiece& replace);

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

}  // namespace strings

#endif  // _STRINGS_STRUTIL_H__
