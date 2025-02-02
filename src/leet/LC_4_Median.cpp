/*
4. Median of Two Sorted Arrays
Hard
23.1K
2.6K
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
#include<iostream>
#include<cmath>
#include<vector>
#include "LC_header.h"
using namespace std;

class Prob4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        nums3.reserve(nums1.size() + nums2.size());
        //std::cout << "After reserve , Capacity:" << nums3.capacity()  << "   Size:" << nums3.size() << std::endl;
       
        std::vector<int>::iterator it1= nums1.begin();
        std::vector<int>::iterator it2=nums2.begin();
        while( it1 != nums1.end() && it2 != nums2.end()){
            if((*it1) < (*it2)){
                nums3.push_back(*it1);
                ++it1;
            } else if ((*it1)>(*it2) ){
                nums3.push_back(*it2);
                ++it2;
            } else {
                nums3.push_back(*it1);
                nums3.push_back(*it2);
                ++it1;
                ++it2;
            }
        }
        
        while(it1 != nums1.end()){
            nums3.push_back(*it1);
            ++it1;
        }
        while(it2 != nums2.end()){
            nums3.push_back(*it2);
            ++it2;
        }
        std::cout << "nums1 elements: "  <<  nums1.size()  << std::endl;
        for (size_t i=0; i< nums1.size(); i++) {
            std::cout << nums1[i]<< " " ;
        }
        std::cout << "\n";
        std::cout << "nums2 elements: "  <<  nums2.size()  << std::endl;
        for (size_t i=0; i< nums2.size(); i++) {
            std::cout << nums2[i]<< " " ;
        }
        std::cout << "\n";
        std::cout << "nums3 elements: "  <<  nums3.size()  << std::endl;
        for (size_t i=0; i< nums3.size(); i++) {
            std::cout << nums3.at(i)<< " " ;
        }
        std::cout << "\n";
        int a = nums3.size();
        int b = a/2;
        if(a%2 == 0) {
            return ((nums3.at(b)+nums3.at(b-1))/2.0);
        } else {
            return (nums3.at(b));
        }       
    }
};

void test_leet_prob4(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : LeetCode Problem 4                               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    Prob4 p=Prob4();
    std::vector<int> nums1 = {1,2}, nums2 = {3,4}, v1={1,3}, v2 = {2};
    double  m = p.findMedianSortedArrays(nums1, nums2);
    //std::cout <<"num1 size: " << nums1.size() <<" num2 size: " << nums2.size() << std::endl;
    
    std::cout << "median = " << m << std::endl;
    //std::cout <<"v1 size: " << v1.size() <<" v size: " << v2.size() << std::endl;
    
    double n =p.findMedianSortedArrays(v1, v2);
    std::cout << "median = " << n << std::endl;
}