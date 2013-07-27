// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/strings/path.h"
#include "common/strings/strutil.h"
#include "common/strings/stringpiece.h"

namespace strings {

std::string JoinPath(const StringPiece& a, const StringPiece& b) {
  if (a.empty()) {
    return CleanPath(b);
  }
  return CleanPath(a.as_string() + "/" + b.as_string());
}

std::string CleanPath(const StringPiece& input) {
  bool absolute = HasPrefix(input, "/");
  std::vector<StringPiece> pieces = Split(input, "/");
  std::vector<StringPiece> output;
  int num_deep = 0;
  for (int i = 0; i < pieces.size(); ++i) {
    if (pieces[i] == ".") {
      continue;
    }
    if (pieces[i] == "..") {
      if (!output.empty() && output.back() != "..") {
        output.resize(output.size() - 1);
      } else if (!absolute) {
        output.push_back(pieces[i]);
      }
    } else {
      output.push_back(pieces[i]);
    }
  }
  if (output.empty()) {
    return absolute ? "/" : ".";
  }
  return (absolute ? "/" : "") + Join(output, "/");
}

std::string PathDirname(const StringPiece& input) {
  std::string cleaned = CleanPath(input);
  StringPiece tmp = cleaned;
  size_t pos = tmp.rfind('/');
  if (pos == StringPiece::npos) {
    return ".";
  }
  if (pos == 0) {
    return "/";
  }
  return tmp.substr(0, pos).as_string();
}

}  // namespace strings
