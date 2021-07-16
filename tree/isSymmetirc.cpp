//
// Created by wk on 2021/7/15.
//
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

bool dfs(TreeNode* p, TreeNode* q){
    if(p == nullptr && q == nullptr){
        return true;
    }
    if(p == nullptr || q == nullptr || p->val != q->val){
        return false;
    }
    return dfs(p->left, q->right) && dfs(p->right, q->left);
}

bool isSymmetric(TreeNode * root){
    if(root == nullptr){
        return true;
    }
    return dfs(root->left, root->right);
}

int main(){
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    bool isS = isSymmetric(root);
    cout << isS << endl;
    return 0;
};