//
// Created by wangkai on 2019/9/1.
//

/**
 * 题目描述
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getLeastNumber(vector<int> a,int k){
    vector<int> res;
    if(a.empty()||a.size()<k){
        return res;
    }
    sort(a.begin(),a.end());
    for (int i = 0; i < k; ++i) {
        res.push_back(a[i]);
    }
    return res;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    vector<int> result=getLeastNumber(a,k);

    for (int j = 0; j < k; ++j) {
        cout<<result[j]<<" ";
    }
}
