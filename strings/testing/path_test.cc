// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/strings/path.h"
#include "common/test/test.h"

namespace strings {
namespace {

TEST(StringsPath, JoinPath) {
  EXPECT_EQ("/this/is/a/path", JoinPath("/this/is/a", "path"));
  EXPECT_EQ("/this/is/a/path", JoinPath("../random", "/this/is/a/path"));
}

TEST(StringsPath, CleanPath) {
  EXPECT_EQ("/this/is/path", CleanPath("/this/is/a//../path"));
}

TEST(StringsPath, NumPathComponents) {
  EXPECT_EQ(2, strings::NumPathComponents("what/this"));
  EXPECT_EQ(1, strings::NumPathComponents("/this"));
  EXPECT_EQ(0, strings::NumPathComponents("."));
}

}  // anonymous namespace
}  // namespace strings
