//
// Created by wk on 2019/8/11.
//
#include <iostream>
using  namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next)
};
ListNode * findKthToTail(ListNode* pHead,int k){
    if(pHead== nullptr||k<=0){
        return nullptr;
    }
    //快慢指针法
    ListNode *fast=pHead,*slow=pHead;
    //快指针先走k步
    while (k-1){
        if(fast->next!= nullptr)
            fast=fast->next;
        else{
            return nullptr;
        }
        k--;
    }
    //快慢指针一起走
    while (fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
int main(){
    cout<<"hello list"<<endl;
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
    ListNode*n=pHead->next;
    ListNode*m=findKthToTail(pHead,3);

    for (int j = 0; j <5 ; ++j) {
        cout<<n->val<<endl;
        n=n->next;
    }
    cout<<"倒数第三个节点的值：："<<m->val<<endl;
}

