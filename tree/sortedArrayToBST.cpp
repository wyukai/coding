//
// Created by wk on 2021/7/16.
//
/*
 * 108. Convert Sorted Array to Binary Search Tree
 * 有序数组构建平衡二叉树
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i):val(i), left(nullptr), right(nullptr){}
};

TreeNode* constructBST(vector<int>& nums, int start, int end){
    if(start > end){
        return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode* p = new TreeNode(nums[mid]);
    //构建左子树
    p->left = constructBST(nums, start, mid - 1);
    p->right = constructBST(nums, mid + 1, end);
    return p;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.empty()){
        return nullptr;
    }
    //递归构建BST
    TreeNode* root = constructBST(nums,0, nums.size() - 1);
    return root;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    TreeNode* root = sortedArrayToBST(nums);
    return 0;

}