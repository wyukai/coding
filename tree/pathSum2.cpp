//
// Created by wk on 2021/7/20.
//

/*
 * 113. Path Sum II
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.
 *
 Input: root = [1,2,3], targetSum = 5
Output: []

 回溯求解
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i):val(i), left(nullptr), right(nullptr){};
};
vector<vector<int>> result;
void dfs(TreeNode* root, int target, vector<int>& track){
    track.push_back(root->val);
    target = target - root->val;
    if(!root->left && !root->right && target == 0){
        result.push_back(track);
        return;
    }

    if(root->left){
        dfs(root->left, target, track);
        track.pop_back();
    }
    if(root->right){
        dfs(root->right, target, track);
        track.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int target){
    if(root == nullptr) return {};
    vector<int> track;
    //dfs搜索
    dfs(root, target, track);
    return result;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);

    int target = 8;
    vector<vector<int>> result = pathSum(root, target);
    return 0;
}