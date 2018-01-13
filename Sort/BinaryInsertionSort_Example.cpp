#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &v,int target,int low,int high){
    if (high <= low)
        return (target > v[low])?  (low + 1): low;
    int mid = (low + high)/2;
    if(target == v[mid])
        return mid+1;
    if(target > v[mid]){
        return binarySearch(v, target, mid+1, high);
    } else{
        return binarySearch(v, target, low, mid-1);
    }
}

void sort(vector<int> &v,int size){
    int temp,j,pos;
    for(int i=1;i<size;++i){
        pos=binarySearch(v,v[i],0,i-1);
        temp=v[i];
        for(j=i;j>pos;--j){
            v[j]=v[j-1];
        }
        v[pos]=temp;
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

    return 0;
}

