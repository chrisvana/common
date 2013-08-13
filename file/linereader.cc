// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include <fstream>
#include "common/file/linereader.h"
#include "common/log/log.h"

namespace file {

FileLineReader::FileLineReader(const std::string& filename)
    : done_(false),
      ifstream_(new std::ifstream(filename.c_str(), std::ifstream::in)) {
  CHECK(ifstream_->is_open()) << "Could not open file: " << filename;
  Next();
}

FileLineReader::~FileLineReader() {
  ifstream_->close();
}

void FileLineReader::Next() {
  CHECK(!done_);
  std::getline(*ifstream_, line_);
  done_ = !ifstream_->good();
}

}  // namespace file
