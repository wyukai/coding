//
// Created by Administrator on 2021/4/16.
//

/*
 * 在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
 *
 * 题解：
 * 因为数组已经排好序，我们可以采用方向相反的双指针来寻找这两个数字，一个初始指向最
小的元素，即数组最左边，向右遍历；一个初始指向最大的元素，即数组最右边，向左遍历。
如果两个指针指向元素的和等于给定值，那么它们就是我们要的结果。如果两个指针指向元
素的和小于给定值，我们把左边的指针右移一位，使得当前的和增加一点。如果两个指针指向元
素的和大于给定值，我们把右边的指针左移一位，使得当前的和减少一点。

 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& v, const int target){
    int size = v.size();
    int start = 0, last = size - 1;
    int sum = 0;
    while (start < last){
        sum = v[start] + v[last];
        if(sum == target) break;
        else if(sum < target){
            start++;
        }
        else{
            last--;
        }
    }
    return vector<int>{start + 1, last + 1};
}

// 未排序数组中找出和为某数的两个数的下标
// 使用map，循环遍历数组，每次访问一个元素，将值与其下标存入map中，
vector<int> twoSum1(vector<int>& v, const int target){
    vector<int> result;
    map<int, int> temp;
    for (int i = 0; i < v.size(); ++i) {
        if(temp.count(target - v[i]) != 0){
            result.push_back(i);
            result.push_back(temp[target - v[i]]);
            return result;
        }
        else {
            temp[v[i]] = i;
        }
    }
    return {};
}

int main(){
    vector<int> v;
    for(int i = 0; ;i++){
        int n;
        cin >> n;
        v.push_back(n);
        if(getchar() == '\n'){
            break;
        }
    }
    int target;
    cin >> target;

    vector<int> index_v = twoSum(v, target);
    cout<< index_v[0] <<" "<<index_v[1]<<endl;


}