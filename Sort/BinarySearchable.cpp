#include <iostream>
#include <climits>

using namespace std;

int main(void){

    int n,count=0;
    int v[101];
    int max[101];
    int min[101];
    while(cin>>n){
        count=0;
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        max[0]=INT_MIN;
        for(int i=1;i<n;++i){
            if(v[i-1]>max[i-1]){
                max[i]=v[i-1];
            } else{
                max[i]=max[i-1];
            }
        }
        min[n-1]=INT_MAX;
        for(int i=n-2;i>=0;--i){
            if(v[i+1]<min[i+1]){
                min[i]=v[i+1];
            } else{
                min[i]=min[i+1];
            }
        }
        for(int i=0;i<n;++i){
            if(v[i]<=min[i]&&v[i]>=max[i]){
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}

