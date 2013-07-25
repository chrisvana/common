// Copyright 2013
// Author: Christopher Van Arsdale

#include <fstream>
#include <string>
#include "file/fileutil.h"
#include "log/log.h"

namespace file {

std::string ReadFileToStringOrDie(const std::string& filename) {
  std::ifstream ifs(filename.c_str(), std::ifstream::in);
  CHECK(ifs.is_open()) << "Could not open file: " << filename;
  std::string ret((std::istreambuf_iterator<char>(ifs) ),
                  (std::istreambuf_iterator<char>()    ) );
  CHECK(!ifs.bad()) << "Could not read file: " << filename;
  return ret;
}

}  // namespace file
