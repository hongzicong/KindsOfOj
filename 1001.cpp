#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

bool visit[MAX];
int dist[MAX];
int matrix[MAX][MAX];

int main(int argc, char const *argv[]) {

  int n,m;
  int temp_1,temp_2;
  cin>>n>>m;

  for(int i=0;i<MAX;++i){
    visit[i]=false;
    dist[i]=-1;
  }

  for(int i=0;i<m;++i){
    cin>>temp_1>>temp_2;
    matrix[temp_1-1][temp_2-1]=1;
    matrix[temp_2-1][temp_1-1]=1;
  }

  dist[0]=0;
  queue<int> q;
  q.push(0);
  visit[0]=true;
  while(!q.empty()){
    int temp=q.front();
    q.pop();
    for(int i=0;i<n;++i){
      if(visit[i]==false&&matrix[temp][i]!=0){
        q.push(i);
        dist[i]=dist[temp]+1;
        visit[i]=true;
      }
    }
  }

  for(int i=0;i<n;++i){
    cout<<dist[i]<<" ";
  }

  return 0;
}
