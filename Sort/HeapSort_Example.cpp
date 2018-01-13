#include <iostream>
#include <vector>

using namespace std;

void percolateDown(vector<int> &v,int i,int size){
    int curr=i;
    //每个节点的左子树为2i+1，右子树为2i+2
    //每个节点的父节点为(i-1)/2
    int left=2*i+1;
    int temp=v[i];
    for(;left<size;curr=left,left=2*left+1){
        //若左儿子比右儿子大，则让父节点和右儿子作比较
        if(left+1<size&&v[left]>v[left+1]){
            left++;
        }
        if(temp<=v[left]){
            break;
        } else{
            [](int &a,int &b){int temp=a;a=b;b=temp;}(v[curr],v[left]);
        }
    }
}

void sort(vector<int> &v,int size){
    //从底往上逐层下沉，这样可以让小的慢慢浮上去
    for(int i=(size-2)/2;i>=0;--i){
        percolateDown(v,i,size);
    }
    for(int i=size-1;i>0;--i){
        [](int &a,int &b){int temp=a;a=b;b=temp;}(v[0],v[i]);
        percolateDown(v,0,i);
    }
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
