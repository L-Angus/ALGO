#ifndef TIME_Flex_HPP
#define TIME_Flex_HPP

#include <algorithm>
#include <chrono>
#include <random>
#include <stack>
#include <vector>

#include <iostream>

int constant(int n) {
  int count = 0;
  int size = 10000;
  for (int i = 0; i < size; ++i) {
    count++;
  }
  return count;
}

std::vector<int> randomNumbers(int n) {
  std::vector<int> nums(n);
  for (size_t i = 0; i < n; i++) {
    nums[i] = i + 1;
  }
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));
  return nums;
}

int findOne(std::vector<int> &nums) {
  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
      return i;
    }
  }
  return -1;
}

void TestStack() {
  std::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  int top = stack.top();
  std::cout << "Top element = " << top << std::endl;
  size_t size = stack.size();
  std::cout << "Size = " << size << std::endl;
}

#endif