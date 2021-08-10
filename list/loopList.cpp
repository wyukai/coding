//
// Created by wk on 2019/8/13.
//
#include <iostream>
using  namespace std;

struct ListNode{
    int val;
    ListNode *next;
};
//�������ָ�룬fastһ����������slowһ����һ������������д��ڻ��Ļ�����ָ�����׷����ָ��
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
//�ҵ�������ڽڵ㣬�����ڵ��һ������ʱ����ָ�������ǰ�ߣ���ָ��ָ��ͷ��㣬�Բ���Ϊ1��ǰ�ߣ�����������Ϊ��ڽڵ�
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

//���㻷�а����Ľڵ��� �ӵ�һ��������ʼ��¼�߹��Ľڵ��������ڶ�������ʱֹͣ
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
    //����һ����������
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
        cout<<"�������л� "<<endl<<"������ڽڵ�Ϊ�ڵ㣺"<<findEntry(head)->val<<endl<<"���Ľڵ���ĿΪ��"<<numOfLoop(head)<<endl;
    } else{
        cout<<"����û�л�"<<endl;
    }
    return 0;
}