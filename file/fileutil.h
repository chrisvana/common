// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_FILE_FILEUTIL_H__
#define _COMMON_FILE_FILEUTIL_H__

#include <string>

namespace file {

std::string ReadFileToStringOrDie(const std::string& filename);

}  // namespace file

#endif // _COMMON_FILE_FILEUTIL_H__
