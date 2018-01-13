#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &v,int size){

    int i,j;
    int increment=size;
    do{
        increment=increment/3+1;
        //当increment等于1的时候，就相当于插入排序
        for(i=increment;i<size;i++){
            int temp=v[i];
            for(j=i;j>=increment;j-=increment){
                if(temp<v[j-increment]){
                    v[j]=v[j-increment];
                } else{
                    break;
                }
            }
            v[j]=temp;
        }
    }while(increment>1);
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

    return 0;
}

