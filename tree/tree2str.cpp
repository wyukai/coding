//
// Created by wk on 2021/7/16.
//

/*
 * 606. Construct String from Binary Tree
 * 以前序遍历方式构建string
 */

#include <iostream>
#include <string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i):val(i), left(nullptr), right(nullptr){}
};

string tree2str(TreeNode* root){
    if(root == nullptr){
        return "";
    }
    string s = to_string(root->val);
    // s = s + s_left + s_ right
    if(root->left && root->right){
        s += "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    } else if(root->left){
        s += "(" + tree2str(root->left) + ")";
    } else if(root->right){
        s += "()(" + tree2str(root->right) + ")";
    }
    else{
        return s;
    }
    return s;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    string s = tree2str(root);
    cout << s << endl;
}