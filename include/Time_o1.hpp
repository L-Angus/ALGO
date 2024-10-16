#ifndef TIME_Flex_HPP
#define TIME_Flex_HPP

#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
int constant(int n){
    int count = 0;
    int size = 10000;
    for(int i = 0; i < size; ++i){
        count++;
    }
    return count;
}


std::vector<int> randomNumbers(int n){
    std::vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));
    return nums;
}

int findOne(std::vector<int>& nums){
    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1){
            return i;
        }
    }
    return -1;
}


#endif