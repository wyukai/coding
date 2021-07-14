//
// Created by wk on 2021/7/14.
//
/*
 * 377. 组合总和 Ⅳ
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合(其实是排列的个数)的个数。
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//应该使用动态规划去实现

//方案一  回溯法，， 部分序列可以， 会有超时风险
vector<vector<int>> res;

void dfs(vector<int>& nums, int target, vector<int>& track){
    if(target == 0){
        res.push_back(track);
    }
    for (int i = 0; i < nums.size() && target - nums[i] >= 0; ++i) {
        track.push_back(nums[i]);
        dfs(nums, target - nums[i], track);
        track.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum4(vector<int>& nums, int target){
    sort(nums.begin(),nums.end());
    vector<int> track;
    dfs(nums, target, track);
    return res;
}

int main(){
    vector<int> candidates = {4,2,1};
    int target = 32;
    vector<vector<int>> result = combinationSum4(candidates,target);
    return 0;
}
