//
// Created by wangkai on 2019/9/15.
//

/**
 * 输入一棵树，判断这棵树是否是平衡二叉树
 * 思路：
 * 空树 为平衡二叉树
 * 从根节点开始计算左右子树的深度，判断深度差是否在-1到1之间
 * 递归遍历左右子树的节点，
 *
 */
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
//深度
int depth(TreeNode* pRoot){
    if(pRoot== nullptr) return 0;
    int left=depth(pRoot->left);
    int right=depth(pRoot->right);
    return max(left,right)+1;
}

//是否是二叉平衡树
bool isBalancedSolution(TreeNode *pRoot){
    if(pRoot== nullptr) return true;
    int left=depth(pRoot->left);
    int right=depth(pRoot->right);
    int diff=left-right;
    if(diff>1||diff<-1){
        return false;
    }
    return isBalancedSolution(pRoot->left)&&isBalancedSolution(pRoot->right);

}


int main(){

}