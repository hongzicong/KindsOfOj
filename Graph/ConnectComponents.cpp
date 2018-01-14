#include <iostream>
using namespace std;

int id[1000];
bool visited[1000];

int find(int a){
    while(id[a]!=a){
        a=id[a];
    }
    return a;
}

void union_me(int a,int b){
    int aRoot=find(a);
    int bRoot=find(b);
    id[aRoot]=bRoot;
}

int main(void){

    int n,m;
    cin>>n>>m;

    int a,b;
    for(int i=0;i<n;++i){
        id[i]=i;
        visited[i]=false;
    }

    for(int i=0;i<m;++i){
        cin>>a>>b;
        union_me(a-1,b-1);
    }

    int count=0;
    int temp;
    for(int i=0;i<n;++i){
        temp=i;
        if(visited[i]==false){
            count++;
            while(id[temp]!=temp){
                visited[temp]=true;
                temp=id[temp];
            }
            visited[temp]=true;
        }
    }
    cout<<count<<endl;

    return 0;
}

