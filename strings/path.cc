// Copyright 2013
// Author: Christopher Van Arsdale
//
// TODO(cvanarsdale): This is a garbage library that should be updated with
// something faster/correct. It exists solely for bootstrapping this codebase.

#include <errno.h>
#include <unistd.h>
#include <memory>
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
  return (absolute ? "/" : "") + JoinAll(output, "/");
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

std::string PathBasename(const StringPiece& input) {
  std::string cleaned = CleanPath(input);
  StringPiece tmp = cleaned;
  size_t pos = tmp.rfind('/');
  if (pos == StringPiece::npos) {
    return cleaned;
  }
  return tmp.substr(pos + 1).as_string();
}

std::string CurrentPath() {
  for (int size = 256; size < (1 << 15); size = size << 1) {
    std::unique_ptr<char[]> buff(new char[size]);
    if (getcwd(buff.get(), size)) {
      return std::string(buff.get());
    } else if (errno != ERANGE)  {  // errno == a thread local, apparently :/
      return "";
    }
  }
  return "";
}

int NumPathComponents(const StringPiece& path) {
  std::string tmp = CleanPath(path);
  int count = 0;
  for (StringPiece copy = path; !copy.empty(); ) {
    // Find the next component
    int pos = copy.find('/');
    StringPiece piece = copy;
    if (pos != StringPiece::npos) {
      piece = copy.substr(0, pos);
    }

    // Only count non-empty pieces
    if (!piece.empty() && piece != ".") {
      ++count;
    }

    // Move on.
    copy = copy.substr(piece.size() + 1);
  }
  return count;
}

}  // namespace strings
