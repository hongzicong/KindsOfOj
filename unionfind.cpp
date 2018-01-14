#include <iostream>
using namespace std;

int id[1000];

int find(int a);
void union_me(int a,int b);
bool connected(int a,int b);

int main(int argc, char const *argv[]){

  int a,b;

  for(int i=0;i<100001;++i){
    id[i]=i;
  }

  while(cin>>a>>b){
    if(!connected(a,b)){
      cout<<a<<" "<<b<<endl;
    }
    union_me(a,b);
  }

  return 0;
}

int find(int a){
  while(a!=id[a]){
    a=id[a];
  }
  return a;
}

void union_me(int a,int b){
  int aRoot=find(a);
  int bRoot=find(b);
  id[aRoot]=bRoot;
}

bool connected(int a,int b){
  return find(a)==find(b);
}