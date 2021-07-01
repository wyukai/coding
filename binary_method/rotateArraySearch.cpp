//
// Created by Administrator on 2021/6/29.
//

#include <iostream>
#include <vector>

using namespace std;

bool rotateArraySearch(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return true;
        }
        if(nums[mid] > nums[left]){
            if(target >= nums[left] && target <= nums[mid]){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        else{
            if(target >= nums[mid] && target <= nums[right]){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
    }
    return false;
}


int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 4;
    bool have = rotateArraySearch(nums, target);
    cout << have << endl;
}