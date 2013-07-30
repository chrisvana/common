// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_STRINGS_VARMAP_H__
#define _COMMON_STRINGS_VARMAP_H__

#include <string>
#include <map>

namespace strings {

class VarMap {
 public:
  VarMap() {}
  ~VarMap() {}

  // Mutators.
  void Set(const std::string& key, const std::string& value) {
    replacement_[key] = value;
  }

  // Interface.
  std::string Replace(const std::string& data) const;

 private:
  std::map<std::string, std::string> replacement_;
};

}  // namespace strings

#endif // _COMMON_STRINGS_VARMAP_H__
