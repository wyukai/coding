//
// Created by wk on 2021/8/5.
//
/*
 * 237 删除链表中的节点
 * 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。
 */
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

void deleteNode(ListNode* node){
    if(node == nullptr || node->next == nullptr){
        node = nullptr;
        return;
    }
    node->val = node->next->val;
    node->next = node->next->next;
}