#include <iostream>
#include <queue>

using namespace std;

int n,m;
bool matrix[100][100];
int depth[100];
int width[100];
bool isVisit[100];
bool isValid;

bool isRoot(int num){
  for(int i=0;i<n;++i){
    if(matrix[i][num]==true){
      return false;
    }
  }
  return true;
}

bool allVisited(){
  for(int i=0;i<n;++i){
    if(isVisit[i]==false){
      return false;
    }
  }
  return true;
}

void BFSfunc(int root){
    queue<int> q;
    q.push(root);
    depth[root]=0;
    width[depth[root]]++;

    while(!q.empty()){
      root=q.front();
      q.pop();
      isVisit[root]=true;
      for(int i=0;i<n;++i){
        if(matrix[root][i]){
          if(isVisit[i]==true){
            isValid=false;
            break;
          }
          else{
            q.push(i);
            depth[i]=depth[root]+1;
            width[depth[i]]++;
          }
        }
      }
    }

}

int main(int argc, char const *argv[]) {

  int temp_1,temp_2;
  cin>>n;
  cin>>m;

  while(n!=0){

    isValid=true;

    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        matrix[i][j]=false;
      }
      depth[i]=-1;
      width[i]=0;
      isVisit[i]=false;
    }

    for(int i=0;i<m;++i){
      cin>>temp_1>>temp_2;
      matrix[temp_1-1][temp_2-1]=true;
    }

    int temp;
    for(temp=0;temp<n;++temp){
      if(isValid&&isRoot(temp)){
        BFSfunc(temp);
      }
    }

    if(isValid&&allVisited()){
      int max_depth=-1;
      int max_width=-1;
      for(int i=0;i<n;++i){
        if(depth[i]>max_depth){
          max_depth=depth[i];
        }
        if(width[i]>max_width){
          max_width=width[i];
        }
      }
      cout<<max_depth<<" "<<max_width<<endl;
    }
    else{
      cout<<"INVALID"<<endl;
    }
    cin>>n>>m;
  }

  return 0;
}
