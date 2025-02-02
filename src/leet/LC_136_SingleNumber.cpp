/*
136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1

*/

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

#include <gmock/gmock.h>

/*int single_number(std::vector<int>& nums){
    return std::accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}*/

int single_number2(std::vector<int>& nums){
    int ans = 0;
    for (auto elem : nums){
        ans ^= elem;
    }
    return ans;
}

int single_number3(std::vector<int>& nums){
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size()-1; i += 2){
        if (nums[i] != nums[i+1]) return nums[i];
    }
    return nums[nums.size() - 1];
}

/*TEST(LC, singlenumber){
    std::vector<int>v1{ 2,2,1 };
    std::vector<int>v2{ 4,1,2,1,2 };
    std::vector<int>v3{ 1 };
    EXPECT_EQ(single_number(v1), 1);
    EXPECT_EQ(single_number(v2), 4);
    EXPECT_EQ(single_number(v3), 1);
}*/
TEST(LC, singlenumber2){
    std::vector<int>v1{ 2,2,1 };
    std::vector<int>v2{ 4,1,2,1,2 };
    std::vector<int>v3{ 1 };
    EXPECT_EQ(single_number2(v1), 1);
    EXPECT_EQ(single_number2(v2), 4);
    EXPECT_EQ(single_number2(v3), 1);
}
TEST(LC, singlenumber3){
    std::vector<int>v1{ 2,2,1 };
    std::vector<int>v2{ 4,1,2,1,2 };
    std::vector<int>v3{ 1 };
    EXPECT_EQ(single_number3(v1), 1);
    EXPECT_EQ(single_number3(v2), 4);
    EXPECT_EQ(single_number3(v3), 1);
}