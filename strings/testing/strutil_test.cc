// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/log/log.h"
#include "common/strings/strutil.h"

int main() {
  // HasPrefix
  CHECK(strings::HasPrefix("This is a block", "This"));
  CHECK(!strings::HasPrefix("This", "This is a block"));

  // HasSuffix
  CHECK(strings::HasSuffix("This is a block", "block"));
  CHECK(!strings::HasSuffix("block", "This is a block"));

  // SplitString
  std::vector<std::string> splits = strings::SplitString("foo,bar,baz", ",");
  CHECK_EQ(3, splits.size());
  CHECK_EQ("foo", splits[0]);
  CHECK_EQ("bar", splits[1]);
  CHECK_EQ("baz", splits[2]);

  // Join
  CHECK_EQ("foo,bar,baz", strings::Join(splits, ","));
  CHECK_EQ("foobarbaz", strings::Join(splits, ""));
  CHECK_EQ("", strings::Join(std::vector<std::string>(), ","));

  // Replace
  CHECK_EQ("foo/bar:baz", strings::Replace("foo:bar:baz", ":", "/"));
  CHECK_EQ("foo/bar/baz", strings::ReplaceAll("foo:bar:baz", ":", "/"));

  std::cout << "PASS" << std::endl;
  return 0;
}
