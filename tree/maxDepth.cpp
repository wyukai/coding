//
// Created by wangkai on 2019/8/28.
//

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int maxDepth(TreeNode* node){
    if(node==nullptr){
        return 0;
    }
    int left=maxDepth(node->left);
    int right=maxDepth(node->right);
    return max(left,right)+1;
}

int main(){

};