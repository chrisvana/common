// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/strings/stringpiece.h"

namespace strings {

std::string JoinPath(const StringPiece& a, const StringPiece& b);
std::string CleanPath(const StringPiece& input);
std::string PathDirname(const StringPiece& path);

}  // namespace strings
