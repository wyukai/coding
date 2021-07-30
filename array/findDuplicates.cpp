//
// Created by wk on 2021/7/28.
//
/*
 *Find All Duplicates in an Array 找出数组中所有重复项
 */

#include <iostream>
#include <vector>

using namespace std;
//解法1
vector<int> findDuplicates(vector<int>& nums){
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int pos = abs(nums[i]) - 1;
        if(nums[pos] < 0){
            res.push_back(pos + 1);
        }
        nums[pos] = -nums[pos];
    }
    return res;
}




int main(){
    vector<int> nums = {1,2,2,3};
    vector<int> res = findDuplicates(nums);
    return 0;
}