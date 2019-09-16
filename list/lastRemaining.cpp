//
// Created by wangkai on 2019/9/16.
//

/*
 * 约瑟夫环问题
 * 题目：0, 1, … , n-1 这 n 个数字排成一个圈圈，从数字 0 开始每次从圆圏里删除第 m 个数字。求出这个圈圈里剩下的最后一个数字。
 *
 * 第一种：经典的解法， 用环形链表模拟圆圈。
 * 创建一个总共有 n 个结点的环形链表，然后每次在这个链表中删除第 m 个结点。
 * 由于list并不是一个环形的结构，因此每次跌代器扫描到列表末尾的时候，要把迭代器移到列表的头部。这样就是按照一个圆圈的顺序来遍历这个列表了
 *
 *
 * 第二种方法：找规律
 */

#include <iostream>
#include <list>
using  namespace std;


int lastRemaining(int n,int m){
    //边界
    if(n<1||m<1){
        return -1;
    }
    //定义存储n个节点的环形链表
    list<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(i);
    }
    //定义迭代器
    list<int>::iterator current=numbers.begin();
    //开始删除节点
    while (numbers.size()>1){
        //找到第m个节点只需要走m-1步
        for (int i = 1; i < m; ++i) {
            current++;
            if(current==numbers.end()){
                current=numbers.begin();
            }
        }
        //保存下一节点，删除当前节点
        list<int>::iterator next= ++current;
        if(next==numbers.end()){
            next=numbers.begin();
        }
        --current;
        numbers.erase(current);
        current=next;
    }
    return *(current);
}

int main(){
    int n,m;
    cin>>n>>m;
    int res=lastRemaining(n,m);
    cout<<res;

}