//
// Created by wk on 2019/8/13.
//
#include <iostream>
using  namespace std;

struct ListNode{
    int val;
    ListNode *next;
};
//定义快慢指针，fast一次走两步，slow一次走一步，如果链表中存在环的话，快指针可以追上慢指针
bool loopList(ListNode*head){
    if(head== nullptr||head->next== nullptr){
        return false;
    }
    ListNode* fast=head;
    ListNode* slow=head;
    while (&&slow&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;


}
//找到环的入口节点，快慢节点第一次相遇时，慢指针继续向前走，快指针指向头结点，以步长为1向前走，两者相遇即为入口节点
ListNode * findEntry(ListNode*head){
    if(head== nullptr||head->next== nullptr){
        return  0;
    }
    ListNode* fast=head,*slow=head;
    while (fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            break;
        }
    }
    if(!fast||!fast->next){
        return nullptr;
    }
    fast=head;
    while (fast!=slow){
        fast=fast->next;
        slow=slow->next;
        if(fast==slow){
            break;
        }
    }
    return slow;


}

//计算环中包含的节点数 从第一次相遇开始记录走过的节点数，到第二次相遇时停止
int numOfLoop(ListNode*head){
    if(head== nullptr||head->next== nullptr){
        return  0;
    }
    ListNode* fast=head,*slow=head;
    int length=0;
    bool first=false;
    bool second=false;
    while (fast&&slow){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            if(first) {
                second=true;
                break;
            }
            first=true;
        }
        if(first){
            length++;
        }
    }
    return length;
}

int main(){
    //创建一个环形链表
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
    h3->val=3;
    h3->next=h4;
    h4->val=4;
    h4->next=h5;
    h5->val=5;
    h5->next=h6;
    h6->val=6;
    h6->next=h3;
    ListNode *p=head;
    if(loopList(head)){
        cout<<"该链表有环 "<<endl<<"环的入口节点为节点："<<findEntry(head)->val<<endl<<"环的节点数目为："<<numOfLoop(head)<<endl;
    } else{
        cout<<"链表没有环"<<endl;
    }
    return 0;
}