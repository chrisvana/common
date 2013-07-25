// Copyright 2013
// Author: Christopher Van Arsdale

#include "strings/strutil.h"

bool HasPrefix(const StringPiece& base, const StringPiece& prefix) {
  return base.starts_with(prefix);
}
