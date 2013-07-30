// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_FILE_FILEUTIL_H__
#define _COMMON_FILE_FILEUTIL_H__

#include <string>
#include <vector>

namespace file {

// Reading
std::string ReadFileToStringOrDie(const std::string& filename);

// Writing
void WriteFileOrDie(const std::string& filename,
                    const std::string& data);

// Globbing
bool Glob(const std::string& glob, std::vector<std::string>* out);

}  // namespace file

#endif // _COMMON_FILE_FILEUTIL_H__
