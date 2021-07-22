//
// Created by wk on 2021/7/21.
//

/*
 * 437. Path Sum III 二叉树的路径和之三
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


//解法1
void dfs(TreeNode* root, vector<int>& path, int curSum, int& res, int target){
    if(root == nullptr) return;
    curSum += root->val;
    path.push_back(root->val);
    if(curSum == target) ++res;
    int temp = curSum;
    for (int i = 0; i < path.size()-1; ++i) {
        temp -= path[i];
        if(temp == target) ++res;
    }
    //左子树
    if(root->left){
        dfs(root->left, path, curSum, res, target);
        path.pop_back();
    }
    if(root->right){
        dfs(root->right, path, curSum, res, target);
        path.pop_back();
    }
}

int pathSum(TreeNode* root, int target){
    if(root == nullptr) return 0;
    int count = 0;
    vector<int> path;
    int curSum = 0;
    dfs(root, path, curSum, count, target);
    return count;
}


//解法2
/*
 * 利用两个递归函数， sumUp记录以当前节点为起点，和为target的路径的数量。
 * pathSum3则对当前节点调用sumUp，加上左右孩子节点为起点调用sumUp。
 * 三者的返回值相加就是所求
 */
int sumUp(TreeNode* root, int pre, int target){
    if(!root) return 0;
    int cur = pre + root->val;
    return (cur == target) + sumUp(root->left, cur, target) + sumUp(root->right, cur, target);
}

int pathSum3(TreeNode* root, int target){
    if(!root) return 0;
    return sumUp(root,0,target) + pathSum3(root->left, target) + pathSum3(root->right, target);
}





int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);

    int target = 3;
    int count = pathSum3(root, target);
    cout<< count << endl;

}