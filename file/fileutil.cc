// Copyright 2013
// Author: Christopher Van Arsdale

#include <glob.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
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

namespace {
int glob_err(const char* epath, int errono) {
  // LOG(ERROR) << "Glob error: " << epath << ": " << strerror(errono);
  return 0;
}
}  // namespace

bool Glob(const std::string& glob_pattern,
          std::vector<std::string>* out) {
  glob_t files;
  int status = glob(glob_pattern.c_str(), 0, &glob_err, &files);
  for(int i = 0l; i < files.gl_pathc; ++i) {
    out->push_back(files.gl_pathv[i]);
  }
  globfree(&files);
  return status != GLOB_ERR;
}

}  // namespace file
