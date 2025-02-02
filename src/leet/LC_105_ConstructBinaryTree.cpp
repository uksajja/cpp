#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <gmock/gmock.h>

#include "LC_BinaryTree.hpp"

class LC_105 {
public:
    // Efficient in Time and Memory
    std::unordered_map<int, int> rootIndexMap; // Alternatively, this map can be passed as a parameter to constructTree function

    TreeNode* constructTree(std::vector<int>& preorder, int lowPre, int highPre, std::vector<int>& inorder, int lowIn, int highIn) {
        if (lowPre > highPre)
            return nullptr;
        int rootVal = preorder[lowPre];
        TreeNode* rootNode = new TreeNode(rootVal);
        if (lowPre == highPre)
            return rootNode;
        // The position of the root in inorder
        int d = rootIndexMap[rootVal];
        int n = d - lowIn;

        rootNode->left = constructTree(preorder, lowPre + 1, lowPre + n, inorder, lowIn, d - 1);
        rootNode->right = constructTree(preorder, lowPre + n + 1, highPre, inorder, d + 1, highIn);
        return rootNode;
    }
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        // In each iteration we need the root position in inorder.
        // As vector for inorder does not change, a map can be used to store the index of each root and can be passed on as a parameter.
        // This way, search can be avoided each time.

        // This map can be passed along every time or declare it as a class variable.
        int l = inorder.size();
        for (int i = 0; i < l; i++) {
            rootIndexMap[inorder[i]] = i;
        }
        return constructTree(preorder, 0, l - 1, inorder, 0, l - 1);
    }

    // Method2 - Memory Efficient, but, Time inefficient
    TreeNode* constructTree2(std::vector<int>& preorder, int lowPre, int highPre, std::vector<int>& inorder, int lowIn, int highIn) {
        if (lowPre > highPre)
            return nullptr;
        int rootVal = preorder[lowPre];
        TreeNode* rootNode = new TreeNode(rootVal);
        if (lowPre == highPre)
            return rootNode;

        // The position of the root in inorder
        auto pos = std::find(inorder.begin(), inorder.end(), rootVal);
        int d = std::distance(inorder.begin(), pos);

        d = d - lowIn; // relative position is needed. If we send new pre and in order vectors, this is not needed.

        rootNode->left = constructTree2(preorder, lowPre + 1, lowPre + d, inorder, lowIn, lowIn + d - 1);
        rootNode->right = constructTree2(preorder, lowPre + d + 1, highPre, inorder, lowIn + d + 1, highIn);
        return rootNode;
    }
    TreeNode* buildTree2(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        int l = preorder.size();
        return constructTree2(preorder, 0, l - 1, inorder, 0, l - 1);
    }

    // Method1 - Memory Inefficient and Time Inefficient
    TreeNode* buildTree3(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        int rootVal = preorder[0];
        TreeNode* rootNode = new TreeNode(preorder[0]);
        rootNode->val = rootVal;
        if (preorder.size() == 1)
            return rootNode;

        // The position of the root in inorder
        auto pos = std::find(inorder.begin(), inorder.end(), rootVal);
        int d = std::distance(inorder.begin(), pos);

        std::vector<int> preL = std::vector<int>(preorder.begin() + 1, preorder.begin() + d + 1);
        std::vector<int> inL = std::vector<int>(inorder.begin(), pos);
        rootNode->left = buildTree3(preL, inL);
        std::vector<int> preR = std::vector<int>(preorder.begin() + d + 1, preorder.end());
        std::vector<int> inR = std::vector<int>(pos + 1, inorder.end());
        rootNode->right = buildTree3(preR, inR);
        return rootNode;
    }
};

TEST(LC, BinaryTree) {
    LC_105 sol{};
    std::vector<int> inorderV{ 9,3, 15, 20,7 };
    std::vector<int> preorderV{ 3,9,20,15,7 };
    TreeNode* tree = sol.buildTree(preorderV, inorderV);
    std::vector<int> inorderRes;
    std::vector<int> preorderRes;
    inorder(tree, inorderRes);
    preorder(tree, preorderRes);
    EXPECT_THAT(inorderRes, ::testing::ContainerEq(inorderV));
    /*std::cout << "\nInOrder:" << std::endl;
    inorderTraversal(tree);
    std::cout << "\nPreOrder:" << std::endl;
    preorderTraversal(tree);*/
    EXPECT_THAT(preorderRes, ::testing::ContainerEq(preorderV));
    std::cout << "\n" <<std::endl;
}
TEST(LC, BinaryTree2){
    LC_105 sol{};
    std::vector<int> inorderV{ 9,3, 15, 20,7 };
    std::vector<int> preorderV{ 3,9,20,15,7 };
    TreeNode* tree = sol.buildTree2(preorderV, inorderV);
    std::vector<int> inorderRes;
    std::vector<int> preorderRes;
    inorder(tree, inorderRes);
    preorder(tree, preorderRes);
    EXPECT_THAT(inorderRes, ::testing::ContainerEq(inorderV));
    EXPECT_THAT(preorderRes, ::testing::ContainerEq(preorderV));
    std::cout << "\n" << std::endl;
}
TEST(LC, BinaryTree3){
    LC_105 sol{};
    std::vector<int> inorderV{ 9,3, 15, 20,7 };
    std::vector<int> preorderV{ 3,9,20,15,7 };
    TreeNode* tree = sol.buildTree3(preorderV, inorderV);
    std::vector<int> inorderRes;
    std::vector<int> preorderRes;
    inorder(tree, inorderRes);
    preorder(tree, preorderRes);
    EXPECT_THAT(inorderRes, ::testing::ContainerEq(inorderV));
    EXPECT_THAT(preorderRes, ::testing::ContainerEq(preorderV));
    std::cout << "\n" << std::endl;
}