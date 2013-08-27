// Copyright 2013
// Author: Christopher Van Arsdale

#include <string>
#include "common/strings/strutil.h"
#include "common/test/test.h"

using std::string;
using std::vector;

namespace strings {
namespace {

TEST(Strutil, HasPrefix) {
  EXPECT_TRUE(HasPrefix("This is a block", "This"));
  EXPECT_FALSE(HasPrefix("This", "This is a block"));
}

TEST(Strutil, HasSuffix) {
  EXPECT_TRUE(HasSuffix("This is a block", "block"));
  EXPECT_FALSE(HasSuffix("block", "This is a block"));
}

TEST(Strutil, SplitString) {
  vector<string> splits = SplitString("foo,bar,baz", ",");
  EXPECT_EQ(3, splits.size());
  EXPECT_EQ("foo", splits[0]);
  EXPECT_EQ("bar", splits[1]);
  EXPECT_EQ("baz", splits[2]);
}

TEST(Strutil, Repeat) {
  EXPECT_EQ("asdf_asdf_asdf_", Repeat("asdf_", 3));
  EXPECT_EQ("", Repeat("asdf_", 0));
}

TEST(Strutil, JoinAll) {
  vector<string> splits = SplitString("foo,bar,baz", ",");
  EXPECT_EQ("foo,bar,baz", JoinAll(splits, ","));
  EXPECT_EQ("foobarbaz", JoinAll(splits, ""));
  EXPECT_EQ("", JoinAll(vector<string>(), ","));
}

#ifdef _COMMON_STRINGS_STRUTIL_VARIADIC_TEMPLATE_
TEST(Strutil, Join) {
  EXPECT_EQ("123,foo,1.01", JoinWith(",", 123, "foo", 1.01));
  EXPECT_EQ("foobar", Join("foo", "bar"));
}
#endif

TEST(Strutil, Replace) {
  EXPECT_EQ("foo/bar:baz", Replace("foo:bar:baz", ":", "/"));
  EXPECT_EQ("foo/bar/baz", ReplaceAll("foo:bar:baz", ":", "/"));
}

TEST(Strutil, StringPrintf) {
  EXPECT_EQ("foo_123", StringPrintf("foo_%d", 123))
      << " " << string("foo_123").size()
      << " VS " << StringPrintf("foo_%d", 123).size();
}

}  // anonymous namespace
}  // namespace strings
