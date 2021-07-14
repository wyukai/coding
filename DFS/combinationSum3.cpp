//
// Created by wk on 2021/7/14.
//
/*
 * Leetcode216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。

输入: k = 3, n = 7
输出: [[1,2,4]]

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;

void dfs(int start, int k, int n, vector<int>& track){
    if(track.size() == k && n == 0){
        res.push_back(track);
    }
    for (int i = start; i <= 9 && n - i >= 0; ++i) {
        track.push_back(i);
        dfs(i+1, k, n-i, track);
        track.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum3(int k, int n){
    vector<int> track;
    dfs(1, k, n, track);
    return res;
}

int main(){
    int n = 9;
    int k = 3;
    vector<vector<int>> result = combinationSum3(k ,n);
    return 0;
}