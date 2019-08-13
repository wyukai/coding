//
// Created by wk on 2019/8/13.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
};
//合并两个有序链表，递归思路，判断两个链表的头结点确定新链表的头结点
ListNode* mergeTwoList(ListNode *head1,ListNode* head2){
    ListNode*p1=head1,*p2=head2;
    if(p1== nullptr){
        return p2;
    }
    if(p2== nullptr){
        return p1;
    }
    ListNode* head= nullptr;
    if(p1->val>=p2->val){
        head=p2;
        head->next=mergeTwoList(p1,p2->next);
    }
    else{
        head=p1;
        head->next=mergeTwoList(p1->next,p2);
    }
    return head;
}

int main(){
    ListNode *head1=new ListNode();
    cin>>head1->val;
    head1->next= nullptr;
    ListNode *temp1=head1;
    for (int i = 0; i < 2; ++i) {
        int data1;
        cin>>data1;
        ListNode *p=new ListNode();
        p->val=data1;
        temp1->next=p;
        temp1=p;
        temp1->next= nullptr;
    }
    ListNode *head2=new ListNode();
    cin>>head2->val;
    head2->next= nullptr;
    ListNode *temp2=head2;
    for (int i = 0; i < 3; ++i) {
        int data1;
        cin>>data1;
        ListNode *p=new ListNode();
        p->val=data1;
        temp2->next=p;
        temp2=p;
        temp2->next= nullptr;
    }

    ListNode * p=mergeTwoList(head1,head2);
    while (p){
        cout<<p->val<<" ";
        p=p->next;
    }
}