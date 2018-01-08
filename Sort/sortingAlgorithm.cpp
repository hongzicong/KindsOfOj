#include <iostream>
#include <algorithm>

using namespace std;

int v[100000];

int main(){

    int m,n;
    int temp;
    while(true){
        scanf("%d %d",&n,&m);
        if(n==0&&m==0){
            break;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&temp);
            v[i]=temp;
        }
        sort(begin(v),begin(v)+n,less<int>());
        for(int i=0;i<n;i+=m){
            cout<<v[i]<<((i+m<n)?" ":"");
        }
        cout<<endl;
    }

    return 0;
}
