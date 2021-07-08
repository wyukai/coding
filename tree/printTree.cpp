//
// Created by Administrator on 2021/7/7.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
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


//二叉树分奇偶层打印
vector<vector<int>> printTree_3(TreeNode* root){
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    bool flag = true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> re;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
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
        if(!flag){
            reverse(re.begin(), re.end());
        }
        flag = !flag;
        result.push_back(re);
    }
    return result;
}

//二叉树分奇偶层打印   双边队列
vector<vector<int>>  printTree_4(TreeNode* root){
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    deque<TreeNode*> q;
    q.push_back(root);
    bool flag = true;
    while(!q.empty()){
        vector<int> re;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* temp;
            if(flag){
                temp = q.front();
                q.pop_front();
                re.push_back(temp->val);
                if(temp->left) q.push_back(temp->left);
                if(temp->right) q.push_back(temp->right);
            } else{
                temp = q.back();
                q.pop_back();
                re.push_back(temp->val);
                if(temp->right) q.push_front(temp->right);
                if(temp->left) q.push_front(temp->left);
            }
        }
        flag = !flag;
        result.push_back(re);
    }
    return result;
}

//二叉树分奇偶层打印  队列 + 栈
vector<vector<int>> printTree_5(TreeNode* root){
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        vector<int> re;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* temp = q.front();
            q.pop();
            re.push_back(temp->val);
            if(flag){
                if(temp->left) s.push(temp->left);
                if(temp->right) s.push(temp->right);
            } else{
                if(temp->right) s.push(temp->right);
                if(temp->left) s.push(temp->left);
            }
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        flag = !flag;
        result.push_back(re);
    }
    return result;
}


int main(){
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
//    vector<int> node = printTree(root);
//    for (int i = 0; i < node.size(); ++i) {
//        cout<<node[i] << ",";
//    }
    vector<vector<int>> node = printTree_5(root);
    for (int i = 0; i < node.size() ; ++i) {
        for (int j = 0; j <node[i].size() ; ++j) {
            cout<< node[i][j] << " ";
        }
        cout<< endl;
    }

}