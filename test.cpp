#include <iostream>
#include <vector>
#include "sort.hpp"

void print(const std::vector<int>& v) {
  for (auto&& vi : v) std::cout << vi << ' ';
  std::cout << std::endl;
}

int main() {
  using namespace shirose;

  std::vector<int> v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  print(v);

  bubble_sort(v.begin(), v.end());
  print(v);

  v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  selection_sort(v.begin(), v.end());
  print(v);

  v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  shaker_sort(v.begin(), v.end());
  print(v);

  v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  comb_sort(v.begin(), v.end());
  print(v);

  v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  norm_sort(v.begin(), v.end());
  print(v);

  v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  shell_sort(v.begin(), v.end());
  print(v);

  v = {10, 3, 1, 2, 6, 4, 5, 8, 9, 7};
  insertion_sort(v.begin(), v.end());
  print(v);
}