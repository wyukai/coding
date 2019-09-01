//
// Created by wangkai on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * 题目描述：
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 * @return
 */

//方法一：hash_table 实现

int moreThanHalfNum(vector<int> a){
    if(a.size()==0) return 0;
    map<int,int> m;
    int length=a.size();
    //哈希表中存数据  key= a[i]  value=a[i]代表的值出现的次数
    for (int i = 0; i < a.size(); ++i) {
        ++m[a[i]];
    }
    //遍历哈希表，判断是否存在超过数组长度一半的元素
    for (auto member:m) {
        if(member.second>length/2){
            return member.first;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int result=moreThanHalfNum(a);
    cout<<"数组中出现次数超过数组长度一半的数字为："<<result;
    return 0;

}