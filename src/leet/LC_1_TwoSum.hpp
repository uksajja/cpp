/*
LC_1 - Two Sum 

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
YoutubeLink: 
https://www.youtube.com/watch?v=UXDSeD9mN-k
*/

#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <set>
#include<unordered_set>
#include <LC_BinaryTree.hpp>

#include <gmock/gmock.h>

std::vector<int> twoSum_Optimal(std::vector<int>& nums, int target);
std::vector<int> twoSum_TwoPointers(std::vector<int>& nums, int target); //nums is sorted
std::vector<int> twoSum_Bruteforce(std::vector<int>& nums, int target);
std::vector<int> twoSum_Bruteforce2(std::vector<int>& nums, int target);
bool twoSum(TreeNode* root, int target, std::unordered_set<int>& s);
bool twoSum_BinaryTree(TreeNode* root, int k);




