#include <gtest/gtest.h>
#include <vector>
#include "sort.hpp"

namespace sh = shirose;

class SortTest : public ::testing::Test {
 protected:
  void SetUp() override {
    v_ = std::vector<int>({10, 3, 1, 4, 2, 6, 4, 5, 7, 8, 9, 7});
    v_ans_ = std::vector<int>({1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10});
  }

  std::vector<int> v_;
  std::vector<int> v_ans_;
};

TEST_F(SortTest, BubbleSort) {
  sh::bubble_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}

TEST_F(SortTest, SelectionSort) {
  sh::selection_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}

TEST_F(SortTest, ShakerSort) {
  sh::shaker_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}

TEST_F(SortTest, CombSort) {
  sh::comb_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}

TEST_F(SortTest, NormSort) {
  sh::norm_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}

TEST_F(SortTest, ShellSort) {
  sh::shell_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}

TEST_F(SortTest, InsertionSort) {
  sh::insertion_sort(v_.begin(), v_.end());
  for (size_t i = 0; i < v_.size(); ++i) EXPECT_EQ(v_[i], v_ans_[i]);
}
