//
// Created by Dv00 on 2018/1/7.
//

#ifndef TEST_LIST_H
#define TEST_LIST_H

struct ListNode{
    int data;
    ListNode *next;
};

class List {
public:
    List(){
        head=new ListNode;
        head->next= nullptr;
    }

    ~List(){
        ListNode* curNode;
        while(head->next){
            curNode=head->next;
            head->next=curNode->next;
            delete curNode;
        }
    }
    ListNode* head;
    void insert(int toadd,int pos);
    void remove(int pos);
};


#endif //TEST_LIST_H
