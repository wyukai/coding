//
// Created by Administrator on 2021/6/29.
//

#include <iostream>
#include <vector>

using namespace std;


int lower_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size(), mid;
    while(l < r){
        mid = (l + r) / 2;
        if(nums[mid] >= target){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;

}

int upper_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size(), mid;
    while(l < r){
        mid = (l + r) / 2;
        if(nums[mid] > target){
            r = mid;
        } else{
            l = mid + 1;
        }
    }
    return l;
}

vector<int> searchRange(vector<int>& nums, int target){
    if(nums.empty()) return vector<int>{-1,-1};
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1;
    if(lower == nums.size() || nums[lower] != target){
        return vector<int>{-1,-1};
    }
    return vector<int> {lower, upper};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 7;
    vector<int> result = searchRange(nums, target);
    cout<< result[0] << " " <<result[1] << endl;
}