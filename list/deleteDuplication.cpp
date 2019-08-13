//
// Created by wk on 2019/8/13.
//
#include <iostream>
using  namespace std;
struct ListNode{
    int val;
    ListNode* next;
};
/*
 * 1）传NULL
2）只有一个节点
3）头节点开始就有重复
4）中间节点重复
5）尾部节点重复
6）链表中没有重复链表
7）所有节点都是重复的
 * */
ListNode *deleteDuplication(ListNode* head){
    if(head== nullptr){
        return nullptr;
    }
    //判断是否只有一个节点
    if(head->next== nullptr){
        return head;
    }
    //采用带头结点的结构，添加一个头结点
    ListNode *pre =new ListNode();
    pre->next=head;  //头节点链接到链表上
    ListNode *pre_node=pre; //保存头节点，用来返回删除后的链表
    ListNode *cur=head; //当前指针
    ListNode *nex=head->next; //后指针
    while (nex){
        //如果cur和nex重复，继续比较下一个节点，知道不重复为止
        while(nex!= nullptr&&cur->val==nex->val){
            nex=nex->next;
        }
        //删除重复的节点(如果有重复节点，cur->next一定不等于nex)
        if(cur->next!=nex){
            //删除重复节点
            while(cur!=nex){
                pre->next=cur->next;
                delete cur;
                cur=pre->next;
            }
            nex=nex->next;
        } else{
            //没有重复
            pre=cur;
            nex=nex->next;
            cur=cur->next;
        }
    }
    ListNode *pHead=pre_node->next;
    delete pre_node;
    return pHead;
}
int main(){
    ListNode *head=new ListNode();
    ListNode *h2=new ListNode();
    ListNode *h3=new ListNode();
    ListNode *h4=new ListNode();
    ListNode *h5=new ListNode();
    ListNode *h6=new ListNode();
    head->val=1;
    head->next=h2;
    h2->val=2;
    h2->next=h3;
    h3->val=2;
    h3->next=h4;
    h4->val=2;
    h4->next=h5;
    h5->val=5;
    h5->next=h6;
    h6->val=6;
    h6->next= nullptr;
    ListNode *p=deleteDuplication(head);
    while (p){
        cout<<p->val<<" ";
        p=p->next;
    }
    return 0;
}