#include "Sample.h"
#include "gtest/gtest.h"

TEST(SumFuncTest, Two){
  Sample sample;
  sample.sum_func(1, 1);
  ASSERT_EQ(2, sample.get_total());
}

TEST(SumFuncTest, Ten){
  Sample sample;
  sample.sum_func(4, 6);
  ASSERT_EQ(10, sample.get_total());
}