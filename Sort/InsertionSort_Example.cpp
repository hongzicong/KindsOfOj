#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int entry;
    Node *next;
    Node(int n):next(nullptr),entry(n){}
};

void sort(vector<int> &v,int size){
    int j,temp;
    for(i=1;i<size;++i){
        temp=v[i];
        for(j=i;j>0&&temp<v[j-1];--j){
            v[j]=v[j-1];
        }
        v[j]=temp;
    }
}

void sort_linked_list(Node *&root){
    if(root!= nullptr){
        Node *preNode=root;
        Node *curr;
        while(preNode->next!=nullptr){
            curr=preNode->next;
            if(curr->entry<root->entry){
                //preNode不变
                preNode->next=curr->next;
                curr->next=root;
                root=curr;
            }
            else{
                Node *preInsertNode=root;
                while(preInsertNode->next->entry<curr->entry){
                    preInsertNode=preInsertNode->next;
                }
                Node *insertNode=preInsertNode->next;
                if(insertNode!=curr){
                    //preNode不变
                    preNode->next=curr->next;
                    curr->next=insertNode;
                    preInsertNode->next=curr;
                }
                else{
                    //如果curr节点不用移动的话，preNode就向后移一格
                    preNode=curr;
                }
            }
        }
    }
}

int main(void){

    vector<int> v1={3,1,5,2,3,4,4,4,2,4};
    vector<int> v2={1};
    sort(v1,v1.size());
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
    sort(v2,v2.size());
    for(auto i:v2){
        cout<<i<<" ";
    }
    cout<<endl;
    Node *root;
    Node *temp=new Node(3);
    root=temp;
    temp=new Node(0);
    root->next=temp;
    Node *temp2=new Node(1);
    temp->next=temp2;
    temp=new Node(7);
    temp2->next=temp;
    sort_linked_list(root);
    while(root!=nullptr){
        cout<<root->entry<<" ";
        root=root->next;
    }

    return 0;
}