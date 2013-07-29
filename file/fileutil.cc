// Copyright 2013
// Author: Christopher Van Arsdale

#include <fstream>
#include <string>
#include "common/file/fileutil.h"
#include "common/log/log.h"

namespace file {

std::string ReadFileToStringOrDie(const std::string& filename) {
  std::ifstream ifs(filename.c_str(), std::ifstream::in);
  CHECK(ifs.is_open()) << "Could not open file: " << filename;
  std::string ret((std::istreambuf_iterator<char>(ifs) ),
                  (std::istreambuf_iterator<char>()    ) );
  CHECK(!ifs.bad()) << "Could not read file: " << filename;
  ifs.close();
  return ret;
}

void WriteFileOrDie(const std::string& filename,
                    const std::string& data) {
  std::ofstream ofs(filename.c_str(),
                    std::ofstream::out | std::ofstream::binary);
  CHECK(ofs.is_open()) << "Could not open file: " << filename;
  ofs.write(data.data(), data.size());
  CHECK(!ofs.bad()) << "Could not write data to file: " << filename;
  ofs.close();
}

}  // namespace file
