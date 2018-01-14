#include <iostream>
#include <queue>

using namespace std;

int matrix[1000][1000];
int dist[1000];
bool visit[1000];

int main(void){

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            matrix[i][j]=0;
        }
        dist[i]=-1;
        visit[i]=false;
    }

    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        matrix[a-1][b-1]=matrix[b-1][a-1]=1;
    }

    queue<int> q;
    q.push(0);
    dist[0]=0;
    visit[0]=true;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<n;++i){
            if(visit[i]==false&&matrix[temp][i]==1){
                q.push(i);
                visit[i]=true;
                dist[i]=dist[temp]+1;
            }
        }
    }

    for(int i=0;i<n;++i){
        cout<<dist[i]<<" ";
    }

    return 0;
}

