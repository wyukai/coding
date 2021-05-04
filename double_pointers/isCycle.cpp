//
// Created by Administrator on 2021/4/28.
//
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};

/*
 * 给定两个指针，起始位置位于链表开头，每次fast前进两步，slow前进一步。
 * 如果 fast可以走到尽头，那么说明没有环路；如果 fast 可以无限走下去，那么说明一定有环路，且一定存
在一个时刻 slow 和 fast 相遇.
 */
bool loopList(ListNode *head){
    if(head == nullptr || head->next == nullptr){
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast && slow && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == slow){
        return true;
    }
    return false;
}

/*
 *当 slow 和 fast 第一次相遇时，我们将 fast 重新移动到链表开头，并
让 slow 和 fast 每次都前进一步。当 slow 和 fast 第二次相遇时，相遇的节点即为环路的开始点。
 */

ListNode *findEntry(ListNode *head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    ListNode *slow = head, *fast = head;
    while(slow && fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }
    if(!fast || !fast->next)

}

