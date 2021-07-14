//
// Created by wk on 2021/7/14.
//
/*
 * Leetcode40. 组合总和 II
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void dfs(vector<int>& candidates, int start, int target, vector<int>& track){
    if(target == 0){
        res.push_back(track);
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
        track.push_back(candidates[i]);
        dfs(candidates, i+1, target - candidates[i], track);
        track.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    sort(candidates.begin(),candidates.end());
    vector<int> track;
    dfs(candidates, 0, target, track);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}


int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> result = combinationSum2(candidates,target);
    return 0;
}