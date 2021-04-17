//
// Created by wk on 2021/4/15.
//
/*
 * 给出一个字符串S, 找到一个划分, 使得一个字母不会在两个部分出现
 * 题解：
 * 1.遍历字符串, 记录每个字母最后出现的位置
2.设定初始start为-1, last为0
3.再遍历一遍字符串, 当last==当前遍历位置, 即找到一个划分, 添加last-start, 并将start设为当前遍历位置(last取得总是当前字母(t)最后出现的位置,
 如果没有其他出现的更后, 那么最后会停在t最后出现的位置; 相反, 如果有一个字母比last出现得更后, 那么这个字母与前面为同一类, 找它的最后即可)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> partitionLabels(string S){
    vector<int> res;
    int size = S.size();
    int start = 0, last = 0;
    //记录 每个字符最后出现的位置
    unordered_map<char, int> m;
    for(int i = 0; i < size; i++){
        m[S[i]] = i;
    }
    for(int i = 0; i < size; i++){
        last = max(last, m[S[i]]);
        if(i == last){
            res.push_back(last - start + 1);
            start = i + 1;
        }
    }
    return res;
}

int main(){

    string labels = "ababcbacadefegdehijhklij";
    vector<int> num_v = partitionLabels(labels);
    for(int i = 0; i < num_v.size(); i++){
        cout<<num_v[i]<< " ";
    }
    return 0;
}


