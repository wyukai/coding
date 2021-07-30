//
// Created by wk on 2021/7/30.
//
/*
 * [796] 旋转字符串
 题目要求我们不能改变原数组，即不能给原数组排序，又不能用多余空间，那么哈希表神马的也就不用考虑了，
 又说时间小于O(n2)，也就不能用brute force的方法，那我们也就只能考虑用二分搜索法了，
 我们在区别[1, n]中搜索，首先求出中点mid，然后遍历整个数组，统计所有小于等于mid的数的个数，如果个数大于mid，
 则说明重复值在[mid+1, n]之间，反之，重复值应在[1, mid-1]之间，然后依次类推，直到搜索完成，
 此时的low就是我们要求的重复值

 */

#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, const string& goal){
    if(s.size() != goal.size()) return false;
    s = s + s;
    if(s.find(goal) != s.npos){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s = "abcde";
    string goal = "bcde";
    bool flag = rotateString(s, goal);
    cout << flag << endl;
}