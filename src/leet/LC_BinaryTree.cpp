/*
LC_BinaryTree -- This need not be a BST

*/
#include "LC_BinaryTree.hpp"

void inorderTraversal(TreeNode* root){
    if (root == nullptr) return;
    inorderTraversal(root->left);
    std::cout << root->val << "  ";
    inorderTraversal(root->right);
}
void preorderTraversal(TreeNode* root){
    if (root == nullptr) return;
    std::cout << root->val << "  ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root){
    if (root == nullptr) return;   
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << "  ";
}

void inorder(TreeNode* root, std::vector<int>& v){
    if (root == nullptr) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right,v);
}
void preorder(TreeNode* root, std::vector<int>& v){
    if (root == nullptr) return;
    v.push_back(root->val);
    preorder(root->left, v);
    preorder(root->right, v);
}
void postorder(TreeNode* root, std::vector<int>& v){
    if (root == nullptr) return;
    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->val);
}