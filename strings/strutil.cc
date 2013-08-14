// Copyright 2013
// Author: Christopher Van Arsdale
//
// TODO: These functions are in no way efficient.

#include <cstdio>
#include <string>
#include <vector>
#include "common/strings/stringpiece.h"
#include "common/strings/strutil.h"

namespace strings {

std::vector<StringPiece> Split(const StringPiece& base,
                               const StringPiece& delim,
                               bool allow_empty) {
  std::vector<StringPiece> out;
  if (delim.empty()) {
    out.resize(base.size());
    for (int i = 0; i < base.size(); ++i) {
      out[i] = StringPiece(base.substr(i, 1));
    }
  } else {
    StringPiece next = base;
    size_t pos = next.find(delim);
    for (; pos != StringPiece::npos; pos = next.find(delim)) {
      if (allow_empty || pos > 0) {
        out.push_back(next.substr(0, pos));
      }
      next = next.substr(pos + delim.size());
    }
    if (allow_empty || !next.empty()) {
      out.push_back(next);
    }
  }
  return out;
}

std::vector<std::string> SplitString(const StringPiece& base,
                                     const StringPiece& delim,
                                     bool allow_empty) {
  std::vector<StringPiece> pieces = Split(base, delim, allow_empty);
  std::vector<std::string> out(pieces.size());
  for (size_t i = 0; i < pieces.size(); ++i) {
    pieces[i].CopyToString(&out[i]);
  }
  return out;
}

// Join
std::string Join(std::vector<std::string> strings, const StringPiece& delim) {
  if (strings.empty()) {
    return "";
  }
  std::string out = strings[0];
  for (int i = 1; i < strings.size(); ++i) {
    out.append(delim.as_string());
    out.append(strings[i]);
  }
  return out;
}

std::string Join(std::vector<StringPiece> strings, const StringPiece& delim) {
  if (strings.empty()) {
    return "";
  }
  std::string out = strings[0].as_string();
  for (int i = 1; i < strings.size(); ++i) {
    out.append(delim.as_string());
    out.append(strings[i].as_string());
  }
  return out;
}

std::string Replace(const StringPiece& input,
                    const StringPiece& original,
                    const StringPiece& replace) {
  if (original.empty()) {
    return input.as_string();
  }

  int pos = input.find(original);
  if (pos == StringPiece::npos) {
    return input.as_string();
  }
  return (input.substr(0, pos).as_string() +
          replace.as_string() +
          input.substr(pos + original.size()).as_string());
}

std::string ReplaceAll(const StringPiece& input,
                       const StringPiece& original,
                       const StringPiece& replace) {
  if (original.empty()) {
    return input.as_string();
  }

  std::string out;
  for (StringPiece current = input; !current.empty(); ) {
    int pos = current.find(original);
    if (pos == StringPiece::npos) {
      out += current.as_string();
      break;
    }
    out.append(current.substr(0, pos).as_string());
    out.append(replace.as_string());
    current = current.substr(pos + original.size());
  }
  return out;
}

}  // namespace strings
