/*
Level order traversal of a binary tree
*/
#include <queue>
#include <vector>

#include <gmock/gmock.h>

#include "LC_BinaryTree.hpp"

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if(root==nullptr){
        return {};
    }
    std::vector<std::vector<int>> vv;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){ 
        std::vector<int> v;
        int l=q.size();
        for(int i=0; i< l; i++) {
            TreeNode *p=q.front();
            v.push_back(p->val);
            q.pop();            
            if(p->left!=nullptr) {               
                q.push(p->left);
            }
            if(p->right!=nullptr) {
                q.push(p->right);
            }
        }
        if(!v.empty()){
            vv.push_back(v);  
        }                                   
    }
    return vv;
}

TEST(LC, levelorder) {

}