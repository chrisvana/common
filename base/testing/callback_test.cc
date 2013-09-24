// Copyright 2013
// Author: Christopher Van Arsdale

#include "common/base/callback.h"
#include "common/test/test.h"

namespace {

void StaticRun(int* val) {
  *val = 10;
}

class CallbackTest : public testing::Test {
 public:
  CallbackTest() : val_(0) {}

  void RunFunc() {
    val_ = 3;
  }
  void RunFuncVal(int val) {
    val_ = val;
  }

  int val_;
};

TEST_F(CallbackTest, StandaloneClosure) {
  Closure* c = NewCallback(&StaticRun, &val_);
  c->Run();
  EXPECT_EQ(10, val_);
}

TEST_F(CallbackTest, ClassClosure) {
  Closure* c = NewCallback(this, &CallbackTest::RunFunc);
  c->Run();
  EXPECT_EQ(3, val_);
}

TEST_F(CallbackTest, Callback1) {
  Callback1<int*>* c = NewCallback(&StaticRun);
  c->Run(&val_);
  EXPECT_EQ(10, val_);
}

TEST_F(CallbackTest, ClassCallback1) {
  Callback1<int>* c = NewCallback(this, &CallbackTest::RunFuncVal);
  EXPECT_FALSE(c->IsPermanentCallback());
  c->Run(11);
  EXPECT_EQ(11, val_);
}

TEST_F(CallbackTest, PermCallback) {
  Callback1<int>* c = NewPermanentCallback(this, &CallbackTest::RunFuncVal);
  EXPECT_TRUE(c->IsPermanentCallback());
  c->Run(11);
  EXPECT_EQ(11, val_);

  c->Run(12);
  EXPECT_EQ(12, val_);

  c->Run(13);
  EXPECT_EQ(13, val_);
}
}  // anonymous namespace
