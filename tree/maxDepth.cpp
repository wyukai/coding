//
// Created by wangkai on 2019/8/28.
//

#include <iostream>
using namespace std;

int ans = 0;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int i ):val(i),left(nullptr),right(nullptr){}
};

//方案1
int maxDepth(TreeNode* node){
    if(node==nullptr){
        return 0;
    }
    int left=maxDepth(node->left);
    int right=maxDepth(node->right);
    return max(left,right)+1;
}

//方案2
void dfs(TreeNode* p, int deep){
    if(p == nullptr){
        return;
    }
    ans = max(ans, deep);
    if(p->left){
        dfs(p->left, deep + 1);
    }
    if(p->right){
        dfs(p->right, deep + 1);
    }
}

int maxDepth2(TreeNode * root){
    dfs(root, 1);
    return ans;
}


int main(){
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int max_d = maxDepth2(root);
    cout << max_d <<endl;
};