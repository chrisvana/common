// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include <map>
#include "common/strings/varmap.h"
#include "common/strings/strutil.h"

namespace strings {

std::string VarMap::Replace(const std::string& data) const {
  std::string copy = data;
  for (auto it : replacement_) {
    copy = strings::ReplaceAll(copy, it.first, it.second);
  }
  return copy;
}

}  // namespace strings
