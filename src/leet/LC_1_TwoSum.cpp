//LC_1 - Two Sum 

#include "LC_1_TwoSum.hpp"

bool twoSum(TreeNode* root, int target, std::unordered_set<int>& s) {
    if (root == nullptr) return false;
    if (s.find(target - root->val)!=s.end()) return true;
    s.insert(root->val);
    return twoSum(root->left, target, s) || twoSum(root->right, target, s);
}
bool twoSum_BinaryTree(TreeNode* root, int k) {
    std::unordered_set<int> s;
    return twoSum(root, k, s);
}
std::vector<int> twoSum_Optimal(std::vector<int>& nums, int target){   
    std::map<int, int> mp; // map to number - index
    for(int i=0; i<nums.size(); i++){
        int number = nums[i];
        int complement = target - number;
        if(mp.find(complement) != mp.end()){
            return {i, mp[complement]};
        } else{
            mp[number] = i;
        }
    }
    return {-1,-1};
}
std::vector<int> twoSum_TwoPointers(std::vector<int>& nums, int target){
    //nums is in non-decreasing sorted order here
    int lb = 0, ub = nums.size()-1;
    while (lb < ub){
        if(nums[lb] + nums[ub] < target ) {
            lb++;
        } else if( nums[lb] + nums[ub]> target) {
            ub--;
        } else {
            return {lb+1, ub+1};
        } 
    }
    return { -1,-1 };
}
std::vector<int> twoSum_Bruteforce(std::vector<int>& nums, int target){
    size_t l = nums.size();
    for(int i = 0; i<l-1; i++){
        int a = target-nums[i];
        for (int j = i+1; j<l; j++) {
            if(a == nums[j]){ 
                return std::vector<int>{i, j};
            }
        }
    }
    return nums;
}

std::vector<int> twoSum_Bruteforce2(std::vector<int>& nums, int target) {
    size_t l = nums.size();
    for(int i = 0; i<l; i++){
        for (int j = i+1; j<l; j++) {
            if((nums[i]+nums[j]) == target){ 
                return std::vector<int>{i, j};
            }
        }
    }
    return nums;
}

TEST(LC, twosum_Optimal) {
    std::vector<int> v={2,7,11,15};
    int target = 9;
    std::vector<int> ans = twoSum_Optimal(v, target);
    EXPECT_THAT(ans, ::testing::ContainerEq(std::vector<int>{1,0}));
}
TEST(LC, twosum1){
    std::vector<int> v = { 2,7,11,15 };
    int target = 9;
    std::vector<int> ans = twoSum_Bruteforce(v, target);
    EXPECT_THAT(ans, ::testing::ContainerEq(std::vector<int>{0, 1}));
}
TEST(LC, twosum2){
    std::vector<int> v = { 2,7,11,15 };
    int target = 9;
    std::vector<int> ans = twoSum_Bruteforce2(v, target);
    EXPECT_THAT(ans, ::testing::ContainerEq(std::vector<int>{0, 1}));
}
TEST(LC, twosum3){
    std::vector<int> v = { 3,3 };
    int target = 6;
    std::vector<int> ans = twoSum_Optimal(v, target);
    EXPECT_THAT(ans, ::testing::ContainerEq(std::vector<int>{1, 0}));
}
TEST(LC, twosum_TwoPointers){
    std::vector<int> v = { 2,7,11,15 };
    int target = 9;
    std::vector<int> ans = twoSum_TwoPointers(v, target);
    EXPECT_THAT(ans, ::testing::ContainerEq(std::vector<int>{1, 2}));
}
TEST(lc, twoSum_BinaryTree) {
    TreeNode* root;
}