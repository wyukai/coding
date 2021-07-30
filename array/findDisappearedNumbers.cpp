//
// Created by wk on 2021/7/28.
//

/*
 * 448. Find All Numbers Disappeared in an Array (Easy)
题目描述
给定一个长度为 n 的数组，其中包含范围为 1 到 n 的整数，有些整数重复了多次，有些整数
没有出现，求 1 到 n 中没有出现过的整数。
O(1)空间和O(n)时间内完成

 对于每个数字nums[i]，如果其对应的nums[nums[i] - 1]是正数，我们就赋值为其相反数，
 如果已经是负数了，就不变了，那么最后我们只要把留下的整数对应的位置加入结果res中即可
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums){
    vector<int> res;
    for (const int & num: nums) {
        int pos = abs(num) - 1;
        if(nums[pos]>0){
            nums[pos] = -nums[pos];
        }
    }
    for (int j = 0; j < nums.size(); ++j) {
        if(nums[j] > 0){
            res.push_back(j + 1);
        }
    }
    return res;
}

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = findDisappearedNumbers(nums);
    return 0;
}