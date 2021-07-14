//
// Created by wk on 2021/7/14.
//

/*
 * Leetcode90. 子集 II
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 输入: [1,2,2]
输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
void dfs(vector<int>& nums, int start, vector<int>& track){
    res.push_back(track);
    for (int i = start; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        dfs(nums, i+1, track);
        track.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    // define backtracking vector
    vector<int> track;
    dfs(nums, 0, track);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()),res.end());
    return res;
}

int main(){
    vector<int> nums = {1,1};
//    while(1){
//        int m;
//        cin >> m;
//        nums.push_back(m);
//        if(cin.get() == '\n'){
//            break;
//        }
//    }
    vector<vector<int>> result = subsetsWithDup(nums);
    int a = 6;
    return 0;
}