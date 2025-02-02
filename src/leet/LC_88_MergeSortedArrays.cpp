/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


*/

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

#include <gmock/gmock.h>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i=m-1;
    int j = n-1;
    for(int pos = m+n-1; pos>=0; pos-- ) {
        if(j<0) return;
        else if(i<0){
            nums1[pos] = nums2[j];
            j--;
        } else if(nums1[i]<=nums2[j]){
            nums1[pos] = nums2[j];
            j--;
        } else {
            nums1[pos] = nums1[i];
            i--;
        } 
    }
}

TEST(LC, MergeArrays) {
    std::vector<int>nums1{1};
    std::vector<int>nums2{};
    std::vector<int>res{1};
    int m = 1, n=0;
    merge(nums1, m, nums2, n);
    EXPECT_THAT(nums1, ::testing::ContainerEq(res));
}
TEST(LC, MergeArrays2){
    std::vector<int>nums1{ };
    std::vector<int>nums2{ };
    std::vector<int>res{ };
    int m = 0, n = 0;
    merge(nums1, m, nums2, n);
    EXPECT_THAT(nums1, ::testing::ContainerEq(res));
}
TEST(LC, MergeArrays3){
    std::vector<int>nums1{ 1,2,3,0,0,0 };
    std::vector<int>nums2{ 2,5,6 };
    std::vector<int>res{ 1,2,2,3,5,6 };
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    EXPECT_THAT(nums1, ::testing::ContainerEq(res));
}
TEST(LC, MergeArrays4){
    std::vector<int>nums1{ 2,0 };
    std::vector<int>nums2{ 1 };
    std::vector<int>res{ 1,2 };
    int m = 1, n = 1;
    merge(nums1, m, nums2, n);
    EXPECT_THAT(nums1, ::testing::ContainerEq(res));
}