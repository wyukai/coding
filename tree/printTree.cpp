//
// Created by Administrator on 2021/7/7.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
// 二叉树从上往下，从左往右依次打印
vector<int> printTree(TreeNode* root){
    vector<int> result;
    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        result.push_back(temp->val);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return result;
}
// 二叉树分层打印
vector<vector<int>> printTree_2(TreeNode* root){
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        // size 用来记录queue的长度，即每层节点的个数。
        int size = q.size();
        vector<int> re;
        for(int i=0; i < size; i++){
            TreeNode* temp = q.front();
            q.pop();
            re.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        result.push_back(re);
    }
}

int main(){
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
//    vector<int> node = printTree(root);
//    for (int i = 0; i < node.size(); ++i) {
//        cout<<node[i] << ",";
//    }
    vector<vector<int>> node = printTree_2(root);
    for (int i = 0; i < node.size() ; ++i) {
        for (int j = 0; j <node[i].size() ; ++j) {
            cout<< node[i][j] << " ";
        }
        cout<< endl;
    }

}