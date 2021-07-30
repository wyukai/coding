//
// Created by wk on 2021/7/29.
//
/*
 * 找出数组中重复的数字。在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，
 * 但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 *
 * 输入：[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 解法1   O(nlogn)
int findRepeatNumber(vector<int>& nums){
    if(nums.empty()) return -1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] == nums[i + 1]){
            return nums[i];
        }
    }
    return -1;
}

//解法2  增加额外空间 O(n)
int findRepeatNumber2(vector<int>& nums){
    if (nums.empty()) return -1;
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
        if(s.count(nums[i]) > 0) return nums[i];
        s.insert(nums[i]);
    }
}


//解法3
int  findRepeatNumber3(vector<int>& nums){
    if(nums.empty()) return -1;
//    for(auto num: nums){
//        num += 1;
//    }
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] += 1;
    }
    for(auto num: nums){
        int pos = abs(num) - 1;
        if(nums[pos] < 0){
            cout << pos;
            return pos;
        }
        nums[pos] = -nums[pos];
    }
    return -1;
}

//解法4
int findRepeatNumbers4(vector<int>& nums){
    if(nums.empty()) return -1;
    for (int i = 0; i < nums.size(); ++i) {
        while(nums[i] != i){
            if(nums[i] == nums[nums[i]]){
                return nums[i];
            }
            else{
                swap(nums[i], nums[nums[i]]);
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    cout << findRepeatNumbers4(nums) << endl;
}