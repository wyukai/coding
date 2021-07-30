//
// Created by wk on 2021/7/30.
//
/*
 * 189 旋转数组
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 三次旋转可解  时间复杂度O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k){
    if(nums.empty() || (k %= nums.size()) == 0) return;
    int len = nums.size();
    reverse(nums.begin(), nums.begin() + len - k);
    reverse(nums.begin() + len - k, nums.end());
    reverse(nums.begin(),nums.end());
}

void rotate1(vector<int>& nums, int k){
    int len = nums.size();
    if(nums.empty() || (k %= len) == 0) return;
    for (int i = 0; i < len - k; ++i) {
        nums.push_back(nums[i]);
        nums.erase(nums.begin());
    }
}


int main(){
    vector<int> nums;
    for(int i = 0; ; i++){
        int t;
        cin >> t;
        nums.push_back(t);
        if(getchar() == '\n'){
            break;
        }
    }
    int k;
    cin >> k;
    rotate1(nums, k);
    for (int j = 0; j < nums.size(); ++j) {
        cout << nums[j] << " " ;
    }
}