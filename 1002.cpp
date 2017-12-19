#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Point{
  int x;
  int y;
};

bool isLegal(int x,int y){
  if(x<=7&&x>=0&&y<=7&&y>=0){
    return true;
  }
  return false;
}

int main(void){

  int count;
  string begin,end;
  bool visit[8][8];
  int dist[8][8];
  int begin_1,begin_2;
  int end_1,end_2;
  int d[8][2]={{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
  cin>>count;

  while(count-->0){
    queue<Point> q;
    for(int i=0;i<8;++i){
      for(int j=0;j<8;++j){
        visit[i][j]=false;
        dist[i][j]=-1;
      }
    }
    cin>>begin>>end;
    begin_1=begin[0]-'a';
    begin_2=begin[1]-'1';
    end_1=end[0]-'a';
    end_2=end[1]-'1';

    Point p;
    int temp_x,temp_y;
    p.x=begin_1;
    p.y=begin_2;
    q.push(p);
    visit[begin_1][begin_2]=true;
    dist[begin_1][begin_2]=0;
    while(!q.empty()){
      p=q.front();
      q.pop();
      temp_x=p.x;
      temp_y=p.y;
      if(temp_x==end_1&&temp_y==end_2){
        break;
      }
      for(int i=0;i<8;++i){
        int next_x=temp_x+d[i][0];
        int next_y=temp_y+d[i][1];
        if(isLegal(next_x,next_y)&&visit[next_x][next_y]==false){
          dist[next_x][next_y]=dist[temp_x][temp_y]+1;
          visit[next_x][next_y]=true;
          p.x=next_x;
          p.y=next_y;
          q.push(p);
        }
      }
    }
    cout<<"To get from "<<begin<<" to "<<end<<" takes "<<dist[end_1][end_2]<<" knight moves."<<endl;
  }

  return 0;
}
