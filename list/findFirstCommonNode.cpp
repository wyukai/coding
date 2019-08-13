//
// Created by wk on 2019/8/13.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};

//计算两个链表的长度差n,长链表先走n步，然后两个一起走，判断相交的节点
ListNode * findFirstCommonNode(ListNode*head1,ListNode *head2){
    if(head1== nullptr||head2== nullptr){
        return nullptr;
    }
    ListNode*p1=head1;
    ListNode*p2=head2;
    //计算两个链表的长度
    int len1=0,len2=0;
    while (p1){
        ++len1;
        p1=p1->next;
    }
    while(p2){
        ++len2;
        p2=p2->next;
    }
    //cout<<"len1: "<<len1<<endl;
    //cout<<"len2: "<<len2<<endl;
    int diff=len1-len2;
    if(diff>0){
        p1=head1;
        p2=head2;
    } else{
        diff=len2-len1;
        p1=head2;
        p2=head1;
    }
    while (diff){
        p1=p1->next;
        diff--;
    }
    //cout<<endl;
    //cout<<p1->val<<endl;
    //cout<<p2->val<<endl;
    while (p2&&p1){
        if(p1->val==p2->val){
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }

    return p2;
}
int main(){
    ListNode *head1=new ListNode();
    cin>>head1->val;
    head1->next= nullptr;
    ListNode *temp1=head1;
    for (int i = 0; i < 4; ++i) {
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
    for (int i = 0; i < 6; ++i) {
        int data1;
        cin>>data1;
        ListNode *p=new ListNode();
        p->val=data1;
        temp2->next=p;
        temp2=p;
        temp2->next= nullptr;
    }
    temp1=head1;
    temp2=head2;
    while(temp1){
        cout<<temp1->val<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
    while(temp2){
        cout<<temp2->val<<" ";
        temp2=temp2->next;
    }

    ListNode *commonNode=findFirstCommonNode(head1,head2);

    cout<<endl<<"fist common node: "<<commonNode->val;
    return 0;

}