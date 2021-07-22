//
// Created by wk on 2021/7/20.
//

/*
 * 112. Path Sum
 * Given the root of a binary tree and an integer targetSum,
 * return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i): val(i), left(nullptr), right(nullptr){};
};

bool dfs(TreeNode* root, int target){
    if(root == nullptr){
        return false;
    }
    if(!root->left && !root->right && target == root->val){
        return true;
    }
    target -= root->val;
    return dfs(root->left, target) || dfs(root->right, target);
}

bool hasPathSum(TreeNode* root, int target){
    if(root == nullptr){
        return false;
    }
    bool flag = dfs(root, target);
    return flag;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);

    int target = 4;
    bool flag = hasPathSum(root, target);
    cout<< flag << endl;
}