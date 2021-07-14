//
// Created by wk on 2021/7/14.
//

/*
 * Leetcode78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

输入: nums = [1,2,3]
输出: [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;

void dfs(vector<int>& nums, int start, vector<int>& track){
    //子集
    cout<< "[";
    for(auto x:track){
        cout << x << " " ;
    }
    cout << ']';
    res.push_back(track);

    for(int i = start; i < nums.size(); ++i){
        track.push_back(nums[i]);
        dfs(nums, i+1, track);
        track.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int>& nums){
    //define  backtracking  vector
    vector<int> track;
    dfs(nums, 0, track);
    return res;
}

int main(){
    vector<int> nums;
    while (1){
        int temp;
        cin>>temp;
        nums.push_back(temp);
        if(cin.get()=='\n'){
            break;
        }
    }

    vector<vector<int>> result = subsets(nums);
    return 0;

}