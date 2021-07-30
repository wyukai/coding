//
// Created by wk on 2021/7/28.
//

/*
 * 287. 寻找重复数
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。 时间复杂度小于O(N*N)


输入：nums = [1,3,4,2,2]
输出：2

输入：nums = [3,1,3,4,2]
输出：3
 */

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums){
    int left = 1, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right) / 2;
        int count = 0;
        for(auto a : nums){
            if(a <= mid) ++count;
        }
        if(count<= mid){
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main(){
    vector<int> nums = {1,1,2};
    cout << findDuplicate(nums) <<endl;
    return 0;
}