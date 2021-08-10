//
// Created by wk on 2021/8/6.
//
/*
 * 3. 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */

/*
 * 滑动窗口解法
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOflongestSubstring(string s){
    int size = s.size();
    int left = 0, right = 0, len = 0, res = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < size - 1; ++i) {
        //找到重复项
        char tempChar = s[right];
        if(m.find(tempChar) != m.end() && m[tempChar] >= left){
            left = m[tempChar] + 1;
            len = right - left;
        }
        m[tempChar] = right;
        ++right;
        ++len;
        res = max(len, res);
    }
    return res;
}

int main(){
    string s ="abcad";
    int maxLenght = lengthOflongestSubstring(s);
    cout << maxLenght << endl;
}