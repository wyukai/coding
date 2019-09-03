//
// Created by wangkai on 2019/9/3.
//
/**
 * 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

说明：
1. 你需要自行定义链表结构，将输入的数据保存到你的链表中；
2. 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换；
3. 你的算法只能使用常数的额外空间。

输入
第一行输入是链表的值
第二行输入是K的值，K是大于或等于1的整数

输入形式为：
1 2 3 4 5
2

 当 k = 2 时，应当输出:
2 1 4 3 5

当 k = 3 时，应当输出:
3 2 1 4 5

当k=6时，应当输出：
1 2 3 4 5
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* reverseListK(ListNode *head, int k){
    if(head== nullptr){
        return nullptr;
    }
    ListNode *pre= nullptr;
    ListNode *left=head;
    ListNode *right=head;
    //将right指针移到第K+1个节点
    for (int i = 0; i < k; ++i) {
        if(right!= nullptr){
            right=right->next;
        }
        else{
            return left;
        }
    }
    ListNode *p=left;
    //反转left至right的这K个节点
    ListNode *post= nullptr;
    while (left!=right){
        post=left->next;
        left->next=pre;
        pre=left;
        left=post;
    }
    p->next=reverseListK(right,k);
    return pre;
}

int main(){
    vector<int> data;
    int temp=0;
    while (1){
        cin>>temp;
        data.push_back(temp);
        if(cin.get()=='\n')
            break;
    }
//    cout<<endl;
//    for (int j = 0; j < data.size(); ++j) {
//        cout<<data[j]<<",";
//    }
//    cout<<endl;
    int k;
    cin>>k;
    //cout<<endl;

    ListNode *head=new ListNode(data[0]);
    ListNode *pHead=head;
    for (int i = 1; i < data.size(); ++i) {
        ListNode* p=new ListNode(data[i]);
        head->next=p;
        head=head->next;
    }
    pHead=reverseListK(pHead,k);
    while (pHead!= nullptr){
        cout<<pHead->val<<" ";
        pHead=pHead->next;
    }
    return 0;
}