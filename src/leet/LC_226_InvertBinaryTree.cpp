//226. Invert Binary Tree
/*
Given the root of a binary tree, invert the tree, and return its root.
Input: root = [2,1,3]
Output: [2,3,1]
*/
#include <iostream>
#include <gmock/gmock.h>

#include "LC_BinaryTree.hpp"

class LC_226 {
    public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        TreeNode *ptr;
        ptr = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(ptr);
    }
};

TEST(LC, inverttree){
}


