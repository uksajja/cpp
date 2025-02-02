//169. Majority Element
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include <gmock/gmock.h>

// Best algorithm -Moore Voting Algorithm
int majorityElement(std::vector<int>& nums){
    int count = 0;
    int major = 0;
    for (int elem : nums){
        if (count == 0){
            major = elem;
        }
        if (elem == major){
            count++;
        }
        else{
            count--;
        }
    }
    return major;
}
// This uses extra space - Not a valid answer
int majorityElement1(std::vector<int>& nums) {
    std::unordered_multiset<int> numset;
    int n = nums.size()/2;
    for (auto elem : nums){
        numset.insert(elem);
        if (numset.count(elem) > n){
            return elem;
        }
    }
    return -1;
}
//Sorting - after sorting the majority element will be at position n/2
int majorityElement2(std::vector<int>& nums){
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}
TEST(LC, majorityElement){
    std::vector<int>v{ 2, 2, 1, 1, 1, 2, 2 };
    EXPECT_EQ(majorityElement(v), 2);
}
TEST(LC, majorityElement1){
    std::vector<int>v{ 2, 2, 1, 1, 1, 2, 2 };
    EXPECT_EQ(majorityElement1(v), 2);
}
TEST(LC, majorityElement2){
    std::vector<int>v{ 2, 2, 1, 1, 1, 2, 2 };
    EXPECT_EQ(majorityElement2(v), 2);
}