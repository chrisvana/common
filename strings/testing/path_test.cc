// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/strings/path.h"
#include "common/test/test.h"

namespace strings {
namespace {

TEST(StringsPath, JoinPath) {
  EXPECT_EQ("/this/is/a/path", JoinPath("/this/is/a", "path"));
}

TEST(StringsPath, CleanPath) {
  EXPECT_EQ("/this/is/path", CleanPath("/this/is/a//../path"));
}

}  // anonymous namespace
}  // namespace strings
