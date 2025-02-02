/*

15. 3Sum
Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

class LeetProb15 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        std::vector<std::vector<int>> vec;
        std::vector<int> v(3);
        std::set<std::vector<int>> s;
        std::sort(nums.begin(), nums.end());
        int a, b, target = 0, l = nums.size();
        int i,j,k;
        for(i=0; i<l; i++) {
            a = target-nums[i];
            j = i+1;
            k = l-1;         
            while(j<k) {
                b = a-nums[j];
                if(nums[k]==b) {
                    v[0] = nums[i]; 
                    v[1] = nums[j]; 
                    v[2] = nums[k];
                    s.insert(v);
                    j++;
                    k--;
                } else if (nums[k]>b){
                    k--;
                } else {
                    j++;
                }
            }
        }
        for(auto& item :s){
            vec.push_back(item);
        }

        //std::cout << vec >> std::endl;
        return vec;
        
    }

    
};
/*
std::vector<int> KSum(std::vector<int>& nums, int l, int u, int k, int target) {
    std::vector<std::vector<int>> vec;
    if(k==2){
        while(l<u) {
            if(target-nums[l]<nums[u]){
                u--;
            }else if(target-nums[j]>nums[k]){
                l++;
            }   else {               
                vec.push_back(std::vector<int>{nums[l], nums[u]});   
                l++;
                u--;             
            }
        }
    }
        
}*/

void Print(std::vector<int>& v){
    for(std::vector<int> ::iterator it = v.begin(); it!=v.end(); it++){
        std::cout << *it << std::endl;
    }
}
void PrintThreeSum(std::vector<std::vector<int>>& v){
for(std::vector<std::vector<int>> ::iterator it = v.begin(); it!=v.end(); it++){
        std::cout << "(" ;
        for(std::vector<int> ::iterator i = (*it).begin(); i!=(*it).end(); i++){
            std::cout << *i << "," ;
        }
        std::cout << ")" << std::endl;
    }
}

void test_leet_prob15(){
    LeetProb15 p = LeetProb15();
    std::vector<int> numbers1 = {-1,0,1,2,-1,-4};
    std::vector<int> numbers2 = {0,1,1};
    std::vector<int> numbers3 = {0,0,0};
    std::vector<int> numbers4 = {0,0,0,0};
    std::vector<std::vector<int>> v1, v2, v3, v4;
    v1 = p.threeSum(numbers1);
    v2 = p.threeSum(numbers2);
    v3 = p.threeSum(numbers3);
    v4 = p.threeSum(numbers4);
    
    PrintThreeSum(v1);
    PrintThreeSum(v2);
    PrintThreeSum(v3);
    PrintThreeSum(v4);
    
    //std::cout << "Input: " << "Output: numbers1" << std::endl;
    
    //std::cout << "Output: " << p.threeSum(numbers2) << std::endl;
    
    //std::cout << "Output: " << p.threeSum(numbers3) << std::endl;
}