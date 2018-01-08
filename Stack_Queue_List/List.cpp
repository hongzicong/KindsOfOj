//
// Created by Dv00 on 2018/1/7.
//

#include "List.h"

void List::insert(int toadd, int pos) {
    ListNode *temp=head;
    for(int i=0;i<pos-1;++i){
        temp=temp->next;
    }
    ListNode *insertNode=new ListNode;
    insertNode->next=temp->next;
    insertNode->data=toadd;
    temp->next=insertNode;
}

void List::remove(int pos) {
    ListNode *temp=head;
    for(int i=0;i<pos-1;++i){
        temp=temp->next;
    }
    ListNode *nextNode=temp->next;
    temp->next=nextNode->next;
    delete nextNode;
}