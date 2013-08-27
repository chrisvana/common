// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include <iostream>
#include "common/base/init.h"
#include "common/log/log.h"
#include "common/strings/strutil.h"

int main(int argc, char** argv) {
  InitProgram(&argc, &argv, true);

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

  // Repeat
  CHECK_EQ("asdf_asdf_asdf_", strings::Repeat("asdf_", 3));
  CHECK_EQ("", strings::Repeat("asdf_", 0));

  // Join
  CHECK_EQ("foo,bar,baz", strings::JoinAll(splits, ","));
  CHECK_EQ("foobarbaz", strings::JoinAll(splits, ""));
  CHECK_EQ("", strings::JoinAll(std::vector<std::string>(), ","));

  // Replace
  CHECK_EQ("foo/bar:baz", strings::Replace("foo:bar:baz", ":", "/"));
  CHECK_EQ("foo/bar/baz", strings::ReplaceAll("foo:bar:baz", ":", "/"));

  // Printf
  CHECK_EQ("foo_123", strings::StringPrintf("foo_%d", 123))
      << " " << std::string("foo_123").size()
      << " VS "
      << strings::StringPrintf("foo_%d", 123).size();

  std::cout << "PASS" << std::endl;
  return 0;
}
