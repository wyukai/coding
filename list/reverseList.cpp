//
// Created by wk on 2019/8/11.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    //初始化
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* ReverseList(ListNode* pHead){
    //定义三个指针
    if(pHead== nullptr){
        return nullptr;
    }
    ListNode *pre= nullptr;
    ListNode *post= nullptr;
    while(pHead){
        post=pHead->next;
        pHead->next=pre;
        pre=pHead;
        pHead=post;
    }
    return pre;
}

int main(){
    cout<<"Hello world"<<endl;
    ListNode *pHead=(ListNode*)malloc(sizeof(ListNode));
    pHead->next= nullptr;
    ListNode *tail;
    tail=pHead;
    ListNode *p;
    for (int i = 0; i <5 ; ++i) {
        int a;
        cin>>a;
        p=(ListNode*)malloc(sizeof(ListNode));
        p->val=a;
        tail->next=p;
        tail=p;
        tail->next= nullptr;
    }
    ListNode *m=ReverseList(pHead->next);
    for (int j = 0; j <5 ; ++j) {
        cout<<m->val<<endl;
        m=m->next;
    }
    system("pause");
    return 0;
}
