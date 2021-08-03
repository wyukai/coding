//
// Created by wk on 2021/8/3.
//
/*
 * Leetcode-783.二叉搜索树节点最小距离
 */

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
long long res = INT8_MAX, last =INT8_MIN;
void inOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    res = min(res, root->val - last);
    last = root->val;
    inOrder(root->right);
}
int minDiffInBST(TreeNode* root){
    inOrder(root);
    return res;
}


int main(){
    auto root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int minDiff = minDiffInBST(root);
    cout << minDiff << endl;
    return 0;
}