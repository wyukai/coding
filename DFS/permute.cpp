//
// Created by wk on 2021/7/13.
//
/*
 * Leetcode46. 全排列
 */

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> res;

// 辅函数
void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans) {
    if (level == nums.size() - 1) {
        ans.push_back(nums);
        return;
    }
    for (int i = level; i < nums.size(); i++) {
        swap(nums[i], nums[level]); // 修改当前节点状态
        backtracking(nums, level+1, ans); // 递归子节点
        swap(nums[i], nums[level]); // 回改当前节点状态
    }
}

// 主函数
vector<vector<int>> permute_1(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
}


void dfs(vector<int>& nums, vector<int> visited){
    if(visited.size() == nums.size()){
        res.push_back(visited);
    }

    for (int i = 0; i < nums.size(); ++i) {
        //已经加入到visited中的点不再加入
        bool contain = false;
        for(auto &x:visited){
            if(nums[i] == x){
                contain = true;
                break;
            }
        }
        if(!contain) {
            visited.push_back(nums[i]);
            dfs(nums, visited);
            visited.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> nums){
    vector<int> visited;
    dfs(nums, visited);
    return res;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = permute(nums);
    int a = 6;
}