//
// Created by Administrator on 2021/6/29.
//

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] < nums[right]){
            right = mid;
        }
        else if(nums[mid] > nums[right]){
            left = mid + 1;
        } else{
            right--;
        }
    }
    return nums[left];
}

int main(){
    vector<int> nums = {4,5,6,-2,-1,1,2};
    int min = findMin(nums);
    cout << "min number in nums  is  "<< min <<endl;
}