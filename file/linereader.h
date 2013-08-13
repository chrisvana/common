// Copyright 2013
// Author: Christopher Van Arsdale
//
// FileLineReader reader("/path/to/file.txt");  // will CHECK on failure.
// for (; !reader.Done(); reader.Next()) {
//   const string& line = reader.line();
// }

#ifndef _COMMON_FILE_LINEREADER_H__
#define _COMMON_FILE_LINEREADER_H__

#include <string>
#include <fstream>

namespace file {

class FileLineReader {
 public:
  explicit FileLineReader(const std::string& filename);
  ~FileLineReader();

  void Next();
  bool Done() const { return done_; }
  const std::string& line() const { return line_; }

 private:
  std::string line_;
  bool done_;
  std::unique_ptr<std::ifstream> ifstream_;
};

}  // namespace file

#endif // _COMMON_FILE_LINEREADER_H__
