//
// Created by wk on 2021/7/13.
//

/*
 * Leetcode77. 组合
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;


void dfs(int n, int k, int start, vector<int> track){
    if(track.size() == k) res.push_back(track);
    for(int i = start; i <= n; ++i){
        track.push_back(i);
        dfs(n,k,i+1,track);
        track.pop_back();
    }
}
vector<vector<int>> combine(int n, int k){
    if(k <= 0 || n <= 0)
        return res;
    vector<int> track;
    dfs(n, k, 1, track);
    return res;
}

int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> res = combine(n,k);
    for(auto i : res){
        cout << "[";
        for(auto j : i){
            cout << j << " " ;
        }
        cout << "]"<< endl;
    }
    return 0;
}
