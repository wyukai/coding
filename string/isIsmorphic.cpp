//
// Created by wk on 2021/8/10.
//
/*
 * Leetcode205.同构字符串
题目：给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:输入: s = “egg”, t = “add” 输出: true

示例 2:输入: s = “foo”, t = “bar” 输出: false

示例 3:输入: s = “paper”, t = “title” 输出: true
 */
#include <iostream>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t){
    if(s.size() != t.size()){
        return false;
    }
    for(int i = 0; i < s.size(); i++){
        if(s.find(s[i]) != t.find(t[i])){
            cout<<  s.find(s[i]) << "  " << t.find(t[i]) << endl;
            //找到两个字符串对应位置字母第一次在字符串中出现的位置
            //若不相等，则说明不是同构字符串
            return false;
        }
    }
    return true;
}

int main(){
    string s = "aba", t = "mnm";
    bool is = isIsomorphic(s, t);
    cout << is << endl;
    return 0;
}