//
// Created by wk on 2021/8/10.
//

/*
 * lc 647 Palindromic Substrings
 * 给定一个字符，求其有多少个回文子字符串。回文的定义是左右对称。
Input: "aaa"
Output: 6
六个回文子字符串分别是 ["a","a","a","aa","aa","aaa"]。
 */
#include <iostream>
#include <string>

using namespace std;


int extendSubstrings(string s, int left, int right){
    int count = 0;
    while(left >= 0 && right <= s.size()- 1 && s[left] == s[right]){
        left--;
        right++;
        count++;
    }
    return count;
}

int countSubString(string s){
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        count += extendSubstrings(s, i, i); //奇数回文字符串
        count += extendSubstrings(s, i, i+1); //偶数回文字符串
    }
    return count;
}

int main(){
    string s = "aaa";
    cout<< countSubString(s) <<endl;
    return 0;

}