//
// Created by wk on 2021/8/10.
//
/*
 * 242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
输入: s = "anagram", t = "nagaram"
输出: true
 */


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, int> hash;
    for(int i = 0; i < s.size(); ++i){
        hash[s[i]] += 1;
    }
    for(int i = 0; i < t.size(); ++i){
        hash[t[i]] -= 1;
    }
    for(int i = 0; i < hash.size(); ++i){
        if(hash[i] != 0){
            return false;
        }
    }
    int i = 10;
    return true;
}

int main(){
    string s = "abc", t = "abc";
    bool is = isAnagram(s, t);
    cout << is << endl;
    return 0;
}

