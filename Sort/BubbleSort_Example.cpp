#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &v,int size){
    bool shouldPass=true;
    for(int i=0;shouldPass&&i<size;++i){
        shouldPass=false;
        for(int j=size-1;j>i;--j){
            if(v[j-1]>v[j]){
                [](int &a,int &b){int temp=a;a=b;b=temp;}(v[j],v[j-1]);
                shouldPass=true;
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

    return 0;
}