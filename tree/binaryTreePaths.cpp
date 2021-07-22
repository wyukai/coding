//
// Created by wk on 2021/7/20.
//
/*
 * 257. Binary Tree Paths 二叉树路径
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i):val(i), left(nullptr), right(nullptr){}
};
void dfs(TreeNode* root, string s, vector<string>& res){
    if(root->left == nullptr && root->right == nullptr){
        res.push_back(s +  to_string(root->val));
    }
    if(root->left != nullptr){
        string s_l = s + to_string(root->val) + "->" ;
        dfs(root->left, s_l, res);
    }
    if(root->right != nullptr){
        string s_r = s + to_string(root->val) + "->" ;
        dfs(root->right, s_r, res);
    }
}

vector<string> binaryTreePaths(TreeNode* root){
    if(root == nullptr) return {};
    vector<string> res;
    string s = "";
    dfs(root, s, res);
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);

    vector<string> result = binaryTreePaths(root);
    for(auto s: result){
        cout << s << endl;
    }
    return 0;
};