#include <iostream>

using namespace std;

struct Node{
    int n;
    Node *next;
    Node():n(0),next(nullptr){}
};

int main(void){

    int n,temp;
    Node *all[13];
    //一定要初始化，否则会出事
    for(int i=0;i<13;++i){
        all[i]=nullptr;
    }
    Node *tempNode;
    while(cin>>n&&n){
        for(int i=0;i<13;++i){
            while(all[i]!= nullptr){
                tempNode=all[i];
                all[i]=all[i]->next;
                delete tempNode;
            }
        }
        int pos;
        for(int i=0;i<n;++i){
            cin>>temp;
            pos=temp%13;
            if(all[pos]== nullptr){
                tempNode=new Node;
                tempNode->n=temp;
                all[pos]=tempNode;
            }
            else{
                tempNode=all[pos];
                while(tempNode->next!=nullptr){
                    tempNode=tempNode->next;
                }
                tempNode->next=new Node;
                tempNode->next->n=temp;
            }
        }
        for(int i=0;i<13;++i){
            cout<<i<<"#";
            tempNode=all[i];
            if(tempNode== nullptr){
                cout<<"NULL";
            }
            else{
                while(tempNode!= nullptr){
                    cout<<tempNode->n<<((tempNode->next==nullptr)?"":" ");
                    tempNode=tempNode->next;
                }
            }
            cout<<endl;
        }
    }

    return 0;
}

