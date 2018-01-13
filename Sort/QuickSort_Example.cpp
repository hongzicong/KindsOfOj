#include <iostream>
#include <vector>

using namespace std;

void exch(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int sort(vector<int> &v,int low,int high){
    //当low等于high时，一个数就不用再排序了，否则有点浪费时间
    if(low<high){
        int middle=low;
        int i=low,j=high+1;
        while(i<=j){
            while(v[++i]<v[middle])
                if(i==high)
                    break;
            while(v[--j]>v[middle])
                if(j==low)
                    break;
            if(i>=j)
                break;
            exch(v[i],v[j]);
        }
        //之所以要和j换的原因是，现在middle所处的是最左边
        //也就是应该小于pivot，可是i与j交叉以后，v[i]是大于pivot的
        //v[j]才是小于pivot的，所以要和j交换
        exch(v[middle],v[j]);
        //现在pivot position是j，所以是以j左右为边界
        sort(v,low,j-1);
        sort(v,j+1,high);
    }
}

int sort_test(vector<int> &v,int low,int high){
    if(low<high){
        int i=low;
        int j=high+1;
        int middle=low;
        while(i<=j){
            while(v[++i]<v[middle])
                if(i==high)
                    break;
            while(v[--j]>v[middle])
                if(j==low)
                    break;
            if(i>=j)
                break;
            exch(v[i],v[j]);
        }
        exch(v[middle],v[j]);
        sort(v,low,j-1);
        sort(v,j+1,high);
    }
}

int main(void){

    vector<int> v1={1,3,5,2,3,4,4,4,2,4};
    vector<int> v2={1};
    sort_test(v1,0,v1.size()-1);
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
    sort_test(v2,0,v2.size()-1);
    for(auto i:v2){
        cout<<i<<" ";
    }

    return 0;
}
