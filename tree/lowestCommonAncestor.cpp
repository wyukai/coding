//
// Created by wk on 2021/7/16.
//
/*
 * 235 Lowest Common Ancestor of a Binary Search Tree
 * 二叉搜索树的最近公共祖先
 *
 */

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i):val(i),left(nullptr),right(nullptr){}
};
// 递归解法
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    int m = root->val, x = p->val, y = q->val;
    //在根节点左侧
    if(x < m && y < m){
        root = lowestCommonAncestor(root->left, p, q);
    }
    //在根节点右侧
    else if(x > m && y > m){
        root = lowestCommonAncestor(root->right, p, q);
    }
    //在当前节点两侧，则此节点即为两个节点的最小公共祖先
    else{
        return root;
    }
    return root;
}

int main(){
    auto root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(4);
    TreeNode* lowestAncestor = lowestCommonAncestor(root, p, q);
    cout << lowestAncestor->val << endl;
}