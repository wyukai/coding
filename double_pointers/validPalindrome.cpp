//
// Created by Administrator on 2021/6/17.
//
#include <iostream>
#include <string>

/*
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 */
using namespace std;

bool isPalindrome(const string &s, int left, int right){
    while(left<right){
        if(s[left] != s[right]){
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

bool validPalindrome(string s){
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        if(s[left] == s[right]){
            ++left;
            --right;
        }
        else{
            return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
        }
    }
    return true;
}

/*
 * Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 */

bool isPalindrome2(string s){
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        while(!isalnum(s[left]) && left < right){
            left++;
        }
        while(!isalnum(s[right]) && left < right){
            right--;
        }
        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;

}

int main(){
    string s = "A man, a plan, a canal: Panama";
    bool isTrue = isPalindrome2(s);
    cout << "is palindrome ::" << isTrue <<endl;
    return 0;
}
