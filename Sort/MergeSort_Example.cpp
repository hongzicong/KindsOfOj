#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v,vector<int> &tempV,int lbegin,int rbegin,int end){
    int begin=lbegin;
    int lend=rbegin-1;
    int i=lbegin;
    while(lbegin<=lend&&rbegin<=end){
        if(v[lbegin]<v[rbegin]){
            tempV[i++]=v[lbegin++];
        }
        else{
            tempV[i++]=v[rbegin++];
        }
    }
    while(lbegin<=lend){
        tempV[i++]=v[lbegin++];
    }
    while(rbegin<=end){
        tempV[i++]=v[rbegin++];
    }
    while(end>=begin){
        v[end]=tempV[end];
        end--;
    }
}

void MSort(vector<int> &v,vector<int> &tempV,int low,int high){
    if(low<high){
        int middle=(low+high)/2;
        MSort(v,tempV,low,middle);
        MSort(v,tempV,middle+1,high);
        merge(v,tempV,low,middle+1,high);
    }
}

void sort(vector<int>& v,int size){
    vector<int> tempV(size);
    MSort(v,tempV,0,size-1);
}

int main(void){

    vector<int> v1={2,3,4,1,2,0,2,19};
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
