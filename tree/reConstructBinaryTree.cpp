//
// Created by wangkai on 2019/8/25.
//
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

/*
 * 题目描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建二叉树并返回。
 */

/*
 * 思路：递归思想，首先从前序遍历序列中确定根节点，然后在中序遍历序列中划分左右子树
 * 并确定左右子树的前序和中序遍历序列，
 * 然后递归查找左右子树中的根节点，分别作为根节点的左右孩子节点。
 */
TreeNode * reConstructBinaryTree(vector<int> pre,vector<int> vin){
    int size=vin.size();
    if(size==0){
        return nullptr;
    }
    //前序遍历序列确定根节点
    TreeNode *root=new TreeNode();
    root->val=pre[0];
    root->left= nullptr;
    root->right= nullptr;
    //确定根节点在中序遍历中的位置索引
    int index;
    for(int i=0;i<size;i++){
        if(vin[i]==pre[0]){
            index=i;
            break;
        }
    }
    //根据索引确定左右子树的前序和中序遍历序列
    vector<int>pre_left,pre_right,vin_left,vin_right;
    for (int j = 0; j <index ; ++j) {
        pre_left.push_back(pre[j+1]);
        vin_left.push_back(vin[j]);
    }
    for (int k = index+1; k <size ; ++k) {
        pre_right.push_back(pre[k]);
        vin_right.push_back(vin[k]);
    }

    //根节点的左孩子为其左子树的根节点
    root->left=reConstructBinaryTree(pre_left,vin_left);
    //根节点的有孩子为其右子树的根节点
    root->right=reConstructBinaryTree(pre_right,vin_right);

    return root;
}
//递归前序遍历
void preOrder(TreeNode* root){
    if(root== nullptr){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    //节点数目
    int n;
    cin>>n;
    //前序序列
    vector<int> pre(n,0);
    vector<int> vin(n,0);
    for (int i = 0; i <n ; ++i) {
        cin>>pre[i];
    }
    for (int i = 0; i <n ; ++i) {
        cin>>vin[i];
    }
    TreeNode *root=reConstructBinaryTree(pre,vin);
    preOrder(root);

    return 0;
}
