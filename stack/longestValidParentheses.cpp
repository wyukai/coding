//
// Created by wk on 2021/7/30.
//
/*
 * 32 最长有效括号
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 * 输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s){
    stack<int> sta;
    int res = 0;
    sta.push(-1);
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '('){
            sta.push(i);
        } else{
            sta.pop();
            if(sta.empty()){
                sta.push(i);
            }
            res = max(res, i - sta.top());
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int res = longestValidParentheses(s);
    cout << res << endl;
}
