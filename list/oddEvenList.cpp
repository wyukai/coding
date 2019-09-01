//
// Created by wangkai on 2019/9/1.
//


/**
 * 奇偶链表
 * 思路：
 * 用两个奇偶指针分别指向奇偶节点的起始位置，另外需要一个单独的指针even_head来保存偶节点的起点位置，
 * 然后把奇节点的指向偶节点的下一个(一定是奇节点)，此奇节点后移一步，
 * 再把偶节点指向下一个奇节点的下一个(一定是偶节点)，
 * 此偶节点后移一步，以此类推直至末尾，此时把分开的偶节点的链表连在奇节点的链表后即可
 */
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
};


ListNode* oddEvenList(ListNode *head){
    if(head== nullptr|| head->next== nullptr){
        return nullptr;
    }
    ListNode* odd=head;
    ListNode* even=odd->next;
    ListNode* p=even;
    while (p!= nullptr&&p->next!= nullptr){
        odd->next=p->next;
        odd=odd->next;
        p->next=odd->next;
        p=p->next;
    }
    odd->next=even;
    return head;
}

int main(){
    int n;
    cin>>n;
    ListNode* head=new ListNode;
    head->val=n;
    head->next= nullptr;
    ListNode *temp=head;
    for (int i = 0; i <5 ; ++i) {
        int a;
        cin>>a;
        ListNode *p=new ListNode;
        p->val=a;
        temp->next=p;
        temp=temp->next;
        temp->next= nullptr;
    }
    ListNode *pHead=head;
    while (head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    ListNode * res=oddEvenList(pHead);
    while (res){
        cout<<res->val<<" ";
        res=res->next;
    }

}