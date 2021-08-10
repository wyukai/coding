//
// Created by wk on 2021/8/10.
//

/*
 * 无序数组中找出所有K, K代表比左边所有数大比右边所有数小的元素。返回所有K在数组中的索引
 */
#include <iostream>
#include <vector>

using namespace std;

//解法一 遍历元素， 对于每个元素分别往前、往后遍历一下， 看看当前元素是否满足条件。

vector<int> findK(vector<int>& nums){
    vector<int> indexs;
    for (int i = 1; i < nums.size()-1; ++i) {
        bool is_max = true, is_min = true;
        for(int n = 0; n < i; ++n){
            if(nums[n] >= nums[i]){
                is_max = false;
                break;
            }
        }
        for (int m = i + 1; m < nums.size() ; ++m) {
            if(nums[m] <= nums[i]){
                is_min = false;
                break;
            }
        }
        if(is_max && is_min){
            indexs.push_back(nums[i]);
        }
    }
    return indexs;
}
//解法2
/*
 * 对于每个元素，如果它比左侧最大的值要大，同时比右侧最小的值要小，就满足条件。
 * 那如果有这样两个数组，

left_max[i] 表示原数组 [0, i) 的最大值

right_min[i] 表示原数组 (i, n) 的最小值

内循环就可以通过 left_max[i] < nums[i] && nums[i] < right_min[i] 来判断

 */
vector<int> findK2(vector<int>& nums){
    vector<int> indexs;
    int n = nums.size();
    vector<int> left_max(n, INT8_MIN), right_min(n,INT8_MAX);

    for(int i = 1; i < n; i++){
        left_max[i] = max(left_max[i-1], nums[i-1]);
    }
    for(int j = n - 2; j >= 0; j--){
        right_min[j] = min(right_min[j+1], nums[j+1]);
    }
    for(int i = 1; i < n-1; i++){
        if(left_max[i] < nums[i] && nums[i] < right_min[i]){
            indexs.push_back(i);
        }
    }
    return indexs;
}


int main(){
    vector<int> nums = {1,2,3,2,5,6,9};
//    vector<int> res = findK(nums);
//    for(auto x: res){
//        cout << x << " ";
//    }
    vector<int> res2 = findK2(nums);
    for(auto x: res2){
        cout << x << " ";
    }
    return 0;
}