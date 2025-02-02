/*

16. 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

*/
#include<iostream>
#include<climits>
#include<vector>
#include<set>
#include<algorithm>
class LeetProb16 {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int minDiff=INT_MAX;
        int a, b, l = nums.size();
        int i,j,k, diff, sum, minSum;
        std::vector<int> v(3);
        for(i=0; i<l; i++) {
            j=i+1;
            k=l-1;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];      
                diff = sum-target;
                if(sum<target){
                    diff = target-sum;
                    if(minDiff>diff){
                        minDiff = diff;
                        minSum = sum;
                        v[0] = nums[i]; 
                        v[1] = nums[j]; 
                        v[2] = nums[k];
                    }
                    j++;               
                } else if(sum>target){
                    diff = sum-target;
                    if(minDiff>diff){
                        minDiff = diff;
                        minSum = sum;
                        v[0] = nums[i]; 
                        v[1] = nums[j]; 
                        v[2] = nums[k];
                    }
                    k--;
                } else {
                    v[0] = nums[i]; 
                    v[1] = nums[j]; 
                    v[2] = nums[k];
                    return sum;
                } 
            }    
        } 
        //std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
        return minSum;
    }
    int threeSumClosest1(std::vector<int>& nums, int target) {
        int minDiff=INT_MAX;
        int a, b, l = nums.size();
        int i,j,k, diff, sum, minSum;
        std::vector<int> v(3);
        for(i=0; i<l-2; i++) {
            for(j=i+1; j<l-1; j++){
                for (k=j+1; k<l; k++){
                    sum = nums[i]+nums[j]+nums[k];
                    diff = abs(sum-target);
                    if(diff<minDiff){
                        minDiff = diff;
                        minSum = sum;
                        v[0] = nums[i]; 
                        v[1] = nums[j]; 
                        v[2] = nums[k];
                    }
                }
            }          
        } 
        //std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
        return minSum;
    }
};

void test_leet_prob16(){
    LeetProb16 p = LeetProb16();
    std::vector<int> v = {-1, 2, 1, -4};
    std::vector<int> v2 = {0,0,0};
    int target = 1;
    std::cout << "Sum is : " << p.threeSumClosest(v, target) << std::endl;
    std::cout << "Sum is : " << p.threeSumClosest(v2, target) << std::endl;
}