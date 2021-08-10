//
// Created by wk on 2021/8/6.
//
/*
 * Leetcode-1695-删除子数组的最大得分
 * 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。
 * 返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。

输入：nums = [4,2,4,5,6]
输出：17
解释：最优子数组是 [2,4,5,6]

输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：最优子数组是 [5,2,1] 或 [1,2,5]

滑动窗口解法
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums){
    int left = 0, right = 0, maxSum = 0, curSum = 0;
    unordered_map<int, int> hash;
    while(right < nums.size()){
        //遇到重复元素
        int temp = nums[right];
        if(hash.find(temp) != hash.end() && hash[temp] >= left){
            while(left <= hash[temp]){
                curSum -= nums[left];
                ++left;
            }
        }
        hash[nums[right]] = right;
        curSum += nums[right];
        maxSum = max(maxSum, curSum);
        ++right;
    }
    return maxSum;
}

int main(){
    vector<int> nums = {5,2,1,2,5,2,1,2,5};
    int maxSum = maximumUniqueSubarray(nums);
    cout << maxSum << endl;
    return maxSum;
}