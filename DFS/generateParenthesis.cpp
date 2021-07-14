//
// Created by wk on 2021/7/14.
//

/*
 * 22. 括号生成
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

输入：n = 1
输出：["()"]
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;

void dfs(string track, int left, int right){
    if(left == 0 && right == 0) result.push_back(track);

    if(left > 0) dfs(track + "(", left - 1, right + 1);
    if(right > 0) dfs(track + ")", left, right - 1);
}

vector<string> generateParenthisis(int n){
    if(n == 0) return result;
    string track = "";
    dfs(track, n, 0);
    return result;
}

int main(){
    int n = 3;
    vector<string> res = generateParenthisis(n);
    for(auto x:res){
        cout << x << " ";
    }
}