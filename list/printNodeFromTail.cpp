//
// Created by wk on 2019/8/13.
//
#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};
//利用栈的先进后出特性
void printNodeFromTail(ListNode *head){
    if(head== nullptr){
        cout<<"链表为空"<<endl;
    }
    else{
        stack<ListNode *> s;
        ListNode *p=head;
        while (p){
            s.push(p);
            p=p->next;
        }
        while (!s.empty()){
            p=s.top();
            cout<<p->val<<" ";
            s.pop();
        }
    }
};

int main(){
    ListNode* head=new ListNode();
    cin>>head->val;
    head->next= nullptr;
    ListNode *temp=head;
    for (int i = 0; i < 4; ++i) {
        int data;
        cin>>data;
        ListNode *p=new ListNode();
        p->val=data;
        temp->next=p;
        temp=p;
        temp->next= nullptr;
    }
    temp=head;
    while (temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    printNodeFromTail(head);
    return 0;
}
