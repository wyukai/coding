//
// Created by Administrator on 2021/4/13.
//
/*
Candy(Hard)
 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。
输入是一个数组，表示孩子的评分。输出是最少糖果的数量

题解
 把所有孩子的糖果数初始化为 1；
先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的
糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数
不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int candy(vector<int>& child_v){
    int size = child_v.size();
    // 只有一个孩子
    if(size < 2){
        return size;
    }
    vector<int> candy_v(size, 1);
    for(int i = 1; i < size; i++){
        if(child_v[i] > child_v[i-1]){
            candy_v[i] = candy_v[i-1] + 1;
        }
    }

    for(int i = size-1; i > 0; i--){
        if(child_v[i] < child_v[i-1]  && candy_v[i] >= candy_v[i-1]){
            candy_v[i-1] = candy_v[i] + 1;
        }
    }
    return accumulate(candy_v.begin(), candy_v.end(),0);
}


using namespace std;
int main(){
    vector<int> child_v;
    for(int i = 0; ; i++){
        int score;
        cin >> score;
        child_v.push_back(score);
        if(getchar() == '\n'){
            break;
        }
    }
    int s = child_v.size();
    while(s){
        cout<< child_v[child_v.size() - s ] << " ";
        --s;
    }

    int min_candy = candy(child_v);
    cout << min_candy;
}