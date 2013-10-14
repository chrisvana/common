// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_STRINGS_PATH_H__
#define _COMMON_STRINGS_PATH_H__

#include <string>
#include "common/strings/stringpiece.h"

namespace strings {

std::string JoinPath(const StringPiece& a, const StringPiece& b);
std::string CleanPath(const StringPiece& input);
std::string PathDirname(const StringPiece& path);
std::string PathBasename(const StringPiece& path);
std::string CurrentPath();
std::string GetRelativePath(const StringPiece& dir, const StringPiece& path);
int NumPathComponents(const StringPiece& path);

}  // namespace strings

#endif  // _COMMON_STRINGS_PATH_H__
