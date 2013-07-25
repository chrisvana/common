// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "strings/stringpiece.h"

namespace strings {

std::string JoinPath(const StringPiece& a, const StringPiece& b);
std::string CleanPath(const StringPiece& input);

}  // namespace strings
