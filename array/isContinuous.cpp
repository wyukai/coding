//
// Created by wangkai on 2019/9/15.
//
/*
 * 扑克牌的顺子
 * 从扑克牌随机抽五张牌，判断是不是一个顺子，2-10位数字本身，A为1，J为11，Q为12，K为13，大小王为0，可以看成任意数字
 *
 * 思路：
 * 数组排序，统计零的数目，统计非零元素的间隔大小，注意是否有对子出现
 */
#include <iostream>
#include <algorithm>
#include <vector>
using  namespace std;

bool isContinuous(vector<int> data){
    if(data.size()<=0){
        return false;
    }
    //排序
    sort(data.begin(),data.end());
    //统计数组中零的数量
    int zero=0;
    for (int i = 0; i <data.size()&&data[i]==0; ++i) {
        ++zero;
    }
    //统计间隔数目 间隔为两个连续数字 data[i+1]-data[i]-1;
    int a=0;
    for (int j = 0; j <data.size()-1 ; ++j) {
        //判断是否为对子
        if(data[j]==data[j+1]){
            return false;
        }
        a+=data[j+1]-data[j]-1;
    }
    //比较zero和a
    if(a<=zero){
        return true;
    } else{
        return false;
    }
}

int main(){
    vector<int> data;
    while (1){
        int temp;
        cin>>temp;
        data.push_back(temp);
        if(cin.get()=='\n'){
            break;
        }
    }
    if(isContinuous(data)) {
        cout<<"顺子";
    } else{
        cout<<"不是顺子";
    }
}
