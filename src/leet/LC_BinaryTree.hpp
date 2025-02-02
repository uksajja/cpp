/*
LC_BinaryTree -- This need not be a BST

*/
/**
 * Definition for a binary tree node.
 */
#pragma once

#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){ }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){ }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){ }
};
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);
void inorder(TreeNode* root, std::vector<int>& v);
void preorder(TreeNode* root, std::vector<int>& v);
void postorder(TreeNode* root, std::vector<int>& v);