#include <iostream>
#include <vector>

using namespace std;

void exch(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int sort(vector<int> &v,int low,int high){
    if(low<high){
        int middle=low;
        int i=low,j=high+1;
        while(i<=j){
            while(v[++i]<v[middle])
                if(i==high)
                    break;
            while(j-1>=low&&v[--j]>v[middle])
                if(j==low)
                    break;
            if(i>=j)
                break;
            exch(v[i],v[j]);
        }
        exch(v[middle],v[j]);
        sort(v,low,i-1);
        sort(v,i+1,high);
    }
}

int main(void){

    vector<int> v={3,1};
    sort(v,0,v.size()-1);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}
