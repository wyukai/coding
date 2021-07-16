//
// Created by wk on 2021/7/16.
//
/*
 * 226. Invert Binary Tree
 * 翻转二叉树
 */

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i): val(i), left(nullptr), right(nullptr){}
};

TreeNode* invertTree(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}

