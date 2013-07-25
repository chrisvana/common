// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include <vector>
#include "strings/stringpiece.h"
#include "strings/strutil.h"

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
