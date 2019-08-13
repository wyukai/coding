//
// Created by wk on 2019/8/13.
//
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

//从链表尾部插入元素
ListNode * insertToTail(ListNode* head,int data){
    //创建新节点将数据保存起来
    ListNode* p=new ListNode();
    p->val=data;
    p->next= nullptr;
    //若头结点为空，则指向新节点
    if(head== nullptr){
        head->next=p;
    }
    else{
        //如果链表有部分数据的话，先走到链表尾部，然后再尾部插入
        ListNode* temp=head;
        while (temp->next){
            temp=temp->next;
        }
        //在链表尾部插入新节点
        temp->next=p;
    }
    return head;
}
int main(){
    ListNode* head=new ListNode();
    cin>>head->val;
    head->next= nullptr;
    ListNode *p;
    for(int i=0;i<5;i++){
        int data;
        cin>>data;
        head=insertToTail(head,data);
    }

    while (head){
        cout<<head->val<<" ";
        head=head->next;
    }
}
