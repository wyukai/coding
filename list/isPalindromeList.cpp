//
// Created by wk on 2021/8/5.
//
/*
 * 27 回文链表
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

//解法1 时间O(n) 空间O(n) 遍历链表将节点值存入vector中，判断vector是否为回文结构
bool isPalindrome(ListNode* head){
    if(head == nullptr || head->next == nullptr) return true;
    vector<int> nums;
    while(head){
        nums.push_back(head->val);
        head = head->next;
    }
    for(int i = 0, j = nums.size(); i < j; ++i, --j){
        if(nums[i] != nums[j]){
            return false;
        }
    }
    return true;
}

/*
 *解法2 快慢指针 遍历到中间节点时，翻转后半部分节点，然后判断前后是否相等即可
 */

ListNode* reverseList(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* left = head;
    ListNode* right = head->next;
    left->next = nullptr;
    while(right){
        ListNode* temp = right->next;
        right->next =left;
        left = right;
        right = temp->next;
    }
    return left;
}

bool isSameList(ListNode* headA, ListNode* headB){
    while(headA && headB){
        if(headA->val != headB->val) return false;
        headA = headA->next;
        headB = headB->next;
    }
}


bool isPalindromeList(ListNode* head){
    if(head == nullptr || head->next == nullptr) return true;
    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        if(fast == nullptr){
            ListNode* temp = slow->next;
            slow->next = nullptr;
            slow = temp;
            break;
        }
        slow = slow->next;
    }
    slow = reverseList(slow);
    return isSameList(head, slow);

}