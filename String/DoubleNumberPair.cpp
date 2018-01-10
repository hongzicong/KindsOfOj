#include <iostream>

using namespace std;

int main(void){

    int T,n,count,temp;
    int v[20];
    cin>>T;
    while(T-->0){
        count=0;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>v[i];
            for(int j=0;j<i;++j){
                if(v[j]*2==v[i]||v[i]*2==v[j]){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }

    return 0;
}