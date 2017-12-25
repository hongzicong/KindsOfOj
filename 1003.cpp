#include <iostream>
#define VER_MAX 100
using namespace std;

bool adjMatrix[VER_MAX][VER_MAX];
bool isVisited[VER_MAX];
int kindMatrix[VER_MAX][VER_MAX];
int n;

void DFSfunc(int begin);
bool isSonVisited(int begin);

int main(int argc, char const *argv[]) {

  int m;
  int temp_1,temp_2;
  cin>>n>>m;
  for(int i=0;i<VER_MAX;++i){
    for(int j=0;j<VER_MAX;++j){
      adjMatrix[i][j]=false;
      kindMatrix[i][j]=-1;
    }
    isVisited[i]=false;
  }

  for(int i=0;i<m;++i){
    cin>>temp_1>>temp_2;
    adjMatrix[temp_1-1][temp_2-1]=true;
  }

  //isVisited[0]一定要放在DFSfunc(0)的前面！！！
  isVisited[0]=true;
  DFSfunc(0);

  cin>>m;
  string result[4]={"Tree Edge", "Back Edge", "Down Edge", "Cross Edge"};
  for(int i=0;i<m;++i){
    cin>>temp_1>>temp_2;
    cout << "edge (" << temp_1 << ',' << temp_2 << ") is " << result[kindMatrix[temp_1-1][temp_2-1]] << endl;
  }
  return 0;
}

bool isSonVisited(int begin){
  for(int i=0;i<n;++i){
    if(adjMatrix[begin][i]&&!isVisited[i]){
      return false;
    }
  }
  return true;
}

void DFSfunc(int begin){
  for(int i=0;i<n;++i){
    if(adjMatrix[begin][i]){
      if(!isVisited[i]){
        kindMatrix[begin][i]=0;
        isVisited[i]=true;
        DFSfunc(i);
      }
      else{
        if(!isSonVisited(i)){
          kindMatrix[begin][i]=1;
        }
        else{
          if(begin==0){
            kindMatrix[begin][i]=2;
          }
          else{
            kindMatrix[begin][i]=3;
          }
        }
      }
    }
  }
}
