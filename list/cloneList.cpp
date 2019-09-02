//
// Created by wangkai on 2019/9/2.
//
/*
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
 * 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 */
/**
 * 复杂链表复制的思路
 * 1、在原有链表的基础上，在每一个结点之后，拷贝一个与这个结点完全相似的结点从而链接到这个结点之后，形成一个完全一致的链表。
 * 2、通过上面的结点拷贝，从而形成了一条链表，但是这条链表上的所有结点都是双份，但是拷贝的结点的random域并没有将其正确指向，
 * 因此通过让拷贝结点的随机域指向原链表结点的random域的下一个结点，因此此时将新链表的random也就正确指向了。
 * 3、在上面的基础上，已经复制了一条新的链表，但是这个链表是与原链表是完全连接在一起的，
 * 因此需要拆解这个链表，从而使得形成两个完全相同的链表（此处注意找新链表的头结点与标记已经拆解到哪个链表上）
 * @return
 */
#include <iostream>
#include <unordered_map>
using namespace std;
struct RandomListNode{
    int label;
    RandomListNode* next,*random;
    RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};



RandomListNode *clone(RandomListNode* head){
    if(head== nullptr){
        return nullptr;
    }
    //步骤一 复制next
    RandomListNode *now=head;
    while (now){
        RandomListNode *newNode=(RandomListNode*)malloc(sizeof(RandomListNode));
        newNode->label=now->label;
        newNode->next= nullptr;
        newNode->random= nullptr;

        //连接
        RandomListNode *nowNext=now->next;
        now->next=newNode;
        newNode->next=nowNext;
        now=nowNext;
    }
    //步骤二  复制random
    now=head;
    while (now){
        RandomListNode *copy=new RandomListNode(now->label);
        copy->random=(now->random== nullptr)? (nullptr):(now->random->next);
        now=now->next->next;
    }
    //步骤三
    now=head;
    RandomListNode *pClone=now->next;
    while (now->next){
        RandomListNode *p=now->next;
        now->next=p->next;
        now=p;
    }
    return pClone;

}

/**
 * 方法二 空间换时间  哈希表
 * @return
 */
 RandomListNode * clone2(RandomListNode *head){
     if(head== nullptr){
         return nullptr;
     }

     //定义哈希表
     unordered_map<RandomListNode*,RandomListNode*> table;

     //定义头节点
     RandomListNode *pCloneHead=new RandomListNode(head->label);
     table.insert(make_pair(head,pCloneHead));

     RandomListNode* pNode=head->next;
     RandomListNode* pClone=pCloneHead;
     //复制链表节点
     while (pNode){
         RandomListNode *newNode=new RandomListNode(pNode->label);
         pClone->next=newNode;
         pCloneHead=newNode;

         table.insert(make_pair(pNode,pCloneHead));

         pNode=pNode->next;
     }

     //设置random节点
     pNode=head;
     pClone=pCloneHead;
     while (pNode){
         if(pNode->random){
             pClone->random=table.find(pNode->random)->second;
         }
         pNode=pNode->next;
         pClone=pClone->next;
     }
     return pCloneHead;
 }
int main(){
    int n;
    cin>>n;
    RandomListNode *head=new RandomListNode(0);
    RandomListNode *p=head;
    for (int i = 0; i <n ; ++i) {
        int val;
        cin>>val;
        RandomListNode * newNode=new RandomListNode(val);
        p->next=newNode;
        p=p->next;
    }
    RandomListNode *q=head;
    for (int j = 0; j < n-1; ++(++j) ){
        q->random=q->next->next;
    }

}
