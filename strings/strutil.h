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

// Repeat
std::string Repeat(const StringPiece& input, int n_times);

// Join
template <typename T>
std::string JoinAll(const T& t, const StringPiece& delim);

template <typename Arg1, typename... T>
std::string JoinWith(const StringPiece& delim,
                     const Arg1& arg1,
                     const T&... args);

template <typename Arg1, typename... T>
std::string Join(const Arg1& arg1, const T&... args) {
  return JoinWith("", arg1, args...);
}

// printf
template <typename T>
std::string StringPrint(const T& t);
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

template <typename T>
inline std::string StringPrint(const T& t) {
  std::stringstream tmp;
  tmp << t;
  return tmp.str();
}

// JoinWith actual work:
template <typename T>
inline void JoinWithSingle(const T& t,
                           std::stringstream* out,
                           const StringPiece& delim) {
  std::string tmp = StringPrint(t);
  if (!tmp.empty()) {
    if (!out->str().empty()) {
      *out << delim;
    }
    *out << tmp;
  }
}

template <typename T>
inline std::string JoinAll(const T& t, const StringPiece& delim) {
  std::stringstream out;
  for (const auto& it : t) {
    JoinWithSingle(it, &out, delim);
  }
  return out.str();
}

// Termination of expansion:
template <typename Arg1>
inline void JoinWithRecurse(std::stringstream* out,
                            const StringPiece& delim,
                            const Arg1& arg1) {
  JoinWithSingle(arg1, out, delim);
}

// Recursive expansion:
template <typename Arg1, typename... T>
inline void JoinWithRecurse(std::stringstream* out,
                            const StringPiece& delim,
                            const Arg1& arg1,
                            T&&... args) {
  JoinWithSingle(arg1, out, delim);
  JoinWithRecurse(out, delim, args...);
}

// JoinWith entry point.
template <typename Arg1, typename... T>
inline std::string JoinWith(const StringPiece& delim,
                            const Arg1& arg1,
                            const T&... args) {
  std::stringstream out;
  JoinWithRecurse(&out, delim, arg1, args...);
  return out.str();
}


}  // namespace strings


#endif  // _STRINGS_STRUTIL_H__
