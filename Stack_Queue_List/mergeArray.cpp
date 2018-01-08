#include <iostream>

using namespace std;

int main(void){

    int a[5];
    int b[5];
    for(int i=0;i<5;++i){
        cin>>a[i];
    }
    for(int i=0;i<5;++i){
        cin>>b[i];
    }

    int i=0,j=0;
    while(i!=5&&j!=5){
        if(a[i]<b[j]){
            cout<<a[i++]<<" ";
        }
        else{
            cout<<b[j++]<<" ";
        }
    }

    while(i!=5){
        cout<<a[i++]<<" ";
    }

    while(j!=5){
        cout<<b[j++]<<" ";
    }

    return 0;
}

