//
// Created by wk on 2021/8/3.
//
/*
 * 19 删除链表的倒数第n个节点
双指针解法
 */

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    if(head == nullptr) return head;
    auto* dummp = new ListNode(0, head);
    ListNode* left = dummp, *right = head;

    for(int i = 0; i < n; ++i){
        right = right->next;
    }
    while(right){
       left = left->next;
           right = right->
                   ;
    }
    left->next= left->next->next;
    return dummp->next;
}

int main(){
    cout<<"hello list"<<endl;
    ListNode* pHead= new ListNode(0);
    ListNode * p = pHead;
    int n;
    cin >> n;

    for (int i = 0; i < 5 ; ++i) {
        int a;
        cin>>a;
        ListNode *temp = new ListNode(a);
        p->next= temp;
        p = p->next;
    }

    ListNode * m = removeNthFromEnd(pHead->next,n);

    for (int j = 0; j <5 ; ++j) {
        cout << m->val << endl;
        m = m->next;
    }
    return 0;
}