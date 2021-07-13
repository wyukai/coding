//
// Created by wk on 2021/7/13.
//
/*
 * Leetcode77. 组合
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;

void dfs(vector<int>& nums, int k, int start, vector<int>& track){
    if(track.size() == k) res.push_back(track);
    for(int i = start; i < nums.size(); ++i){
        track.push_back(nums[i]);
        dfs(nums, k, i+1, track);
        track.pop_back();
    }
}

vector<vector<int>> combine(vector<int>& nums, int k){
    if(nums.empty() || k <= 0) return res;
    vector<int> track;
    dfs(nums, k, 0, track);
    return res;
}

int main(){
    int n, k, m;
    cin >> n >> k;
    vector<int> nums;
    while(n--){
        cin>>m;
        nums.push_back(m);
    }
    res = combine(nums, k);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}