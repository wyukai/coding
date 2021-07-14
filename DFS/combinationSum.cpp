//
// Created by wk on 2021/7/14.
//

/*
 * Leetcode39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
 输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
 输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

void dfs(vector<int>& candidates, int start, int target, vector<int>& track){
    //符合条件的加入结果vector中
    if(target == 0){
        res.push_back(track);
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
        track.push_back(candidates[i]);
        // 无限制选取candidates中的元素，所以下一个选择可以为本身。
        dfs(candidates,i,target-candidates[i], track);
        track.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    // sort
    sort(candidates.begin(), candidates.end());
    // define backtracking vector
    vector<int> track;
    dfs(candidates,0,target,track);
    return res;
}

int main(){
    vector<int> candidates = {1,2,3};
    int target = 4;
    vector<vector<int>> result = combinationSum(candidates,target);
    return 0;
}


