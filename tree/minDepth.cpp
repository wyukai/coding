//
// Created by wk on 2021/7/14.
//

/*
 *111. 二叉树的最小深度
 * 给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
输入：root = [3,9,20,null,null,15,7]
输出：2

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 */
#include <iostream>
#include <queue>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i ):val(i),left(nullptr),right(nullptr){}
};

struct node{
    TreeNode* p;
    int depth;
};

//方案一
int minDepth(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int d = 0;
    while(!q.empty()){
        int size = q.size();
        d += 1;
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left == nullptr && temp->right == nullptr){
                return d;
            }
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return -1;
}

//方案2
int minDepth2(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    queue<node> q;
    q.push(node{root,1});
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        if(temp.p->left == nullptr && temp.p->right == nullptr){
            return temp.depth;
        }
        if(temp.p->left){
            q.push(node{temp.p->left, temp.depth + 1});
        }
        if(temp.p->right){
            q.push(node{temp.p->right, temp.depth + 1});
        }
    }
    return -1;
}



int main(){
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
    int max_d = minDepth2(root);
    cout << max_d <<endl;
}

