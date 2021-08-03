//
// Created by wk on 2021/8/2.
//
/*
 * [80] 删除有序数组中的重复项 II
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。
 */


#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
    int len = nums.size();
    if(len < 2){
        return len;
    }
    int left = 2, right = 2;
    while(right < len){
        if(nums[left - 2] != nums[right]){
            nums[left] = nums[right];
            ++left;
        }
        ++right;
    }
    return left;
}

int removeDuplicates2(vector<int>& nums ,int k){
    int now = 0;
    for(auto x:nums){
        if(now < k || nums[now - k] != x){
            nums[now] = x;
            ++now;
        }
    }
    return now;
}


int main(){
    vector<int> nums ={1,1,2,2,2,3};
    int len = removeDuplicates2(nums,1);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    return len;
}