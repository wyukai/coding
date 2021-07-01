//
// Created by Administrator on 2021/6/29.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums){
    int left = 0, right = nums.size()-1;
    while(left < right){
        int mid = (left + right) / 2;
        if(mid % 2 == 1) mid--;
        if(nums[mid] == nums[mid+1]){
            left = left + 2;
        }
        else{
            right = mid;
        }
    }
    return nums[left];
}

int main(){
    vector<int> nums = {2,2,3,4,4};
    int single = singleNonDuplicate(nums);
    cout << "single number is "<< single <<endl;
}