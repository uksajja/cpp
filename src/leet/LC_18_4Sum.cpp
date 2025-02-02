/*

18. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>


class LeetProb18 {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::vector<std::vector<int>> vec;
    std::vector<int> v(4);
    std::set<std::vector<int>> s;
    std::sort(nums.begin(), nums.end());
    int i, j, k, l, sum;
    int n = nums.size();
    for (i = 0; i < n; i++) {

      for (l = n - 1; l >= 0; l--) {
        j = i + 1;
        k = l - 1;
        while (j < k) {
          std::cout << "(" << i << "," << j << "," << k << "," << l << ")"
                    << std::endl;
          sum = nums[i] + nums[j] + nums[k] + nums[l];
          if (sum < target) {
            j++;
          } else if (sum > target) {
            k--;
          } else {
            v[0] = nums[i];
            v[1] = nums[j];
            v[2] = nums[k];
            v[3] = nums[l];
            s.insert(v);
            j++;
            k--;
          }
        }
      }
    }

    for (auto items : s) {
      vec.push_back(items);
    }
    return vec;
  }
};

void Display(std::vector<std::vector<int>> v) {
  for (std::vector<std::vector<int>>::iterator it = v.begin(); it != v.end();
       it++) {
    std::cout << "[";
    for (std::vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++) {
      std::cout << *i << ",";
    }
    std::cout << "]" << std::endl;
  }
}

void test_leet_prob18() {
  std::cout << "\n------------------------------------------------------------"
            << std::endl;
  std::cout << "    Test : LeetProb18 : FourSum                             "
            << std::endl;
  std::cout << "------------------------------------------------------------"
            << std::endl;
  LeetProb18 p = LeetProb18();
  std::vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  std::vector<std::vector<int>> vec;
  vec = p.fourSum(nums, target);
  Display(vec);
  nums = {2, 2, 2, 2, 2};
  target = 8;
  vec = p.fourSum(nums, target);
  Display(vec);
  std::vector<int> nums3 = {-3, -1, 0, 2, 4, 5};
  target = 2;
  vec = p.fourSum(nums3, target);
  Display(vec);
  std::vector<int> nums4 = {1000000000, 1000000000, 1000000000, 1000000000};
  target = 0;
  vec = p.fourSum(nums4, target);
  Display(vec);
  std::vector<int> nums5 = {1000000000, 1000000000, 1000000000, 1000000000};
  target = -294967296;
  vec = p.fourSum(nums5, target);
  Display(vec);
}