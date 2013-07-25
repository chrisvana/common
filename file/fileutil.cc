// Copyright 2013
// Author: Christopher Van Arsdale

#include <fstream>
#include <string>
#include "file/fileutil.h"
#include "log/log.h"

std::string ReadFileToStringOrDie(const std::string& filename) {
  std::ifstream ifs(filename.c_str(), std::ifstream::in);
  CHECK(ifs.is_open());
  std::string ret((std::istreambuf_iterator<char>(ifs) ),
                  (std::istreambuf_iterator<char>()    ) );
  CHECK(!ifs.bad());
  return ret;
}
