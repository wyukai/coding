//
// Created by wk on 2021/8/4.
//
/*
 * 160 相交链表
 */
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
    if(headA == nullptr || headB == nullptr) return nullptr;
    ListNode* p = headA, *q= headB;
    int m = 0, n = 0;
    while(p){
        p = p->next;
        ++m;
    }
    while(q){
        q = q->next;
        ++n;
    }
    if(m > n){
        for(int i = 0; i < m - n; ++i){
            headA = headA->next;
        }
    }
    if(m < n){
        for(int i = 0; i < n - m; ++i){
            headB = headB ->next;
        }
    }
    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}
