#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct edge {
    int data;
    edge(int d=0):data(d){}
};

int indegree[100000];
vector<edge> matrix[100000];

int main(void){

    int T;
    int temp;
    cin>>T;
    int a,b;
    int n,m;
    set<int> s;
    while(T-->0){
        cin>>n>>m;
        for(int i=0;i<n;++i){
            indegree[i]=0;
            matrix[i].clear();
        }

        for(int i=0;i<m;++i){
            cin>>a>>b;
            matrix[a-1].push_back(edge(b-1));
        }

        for(int i=0;i<n;++i){
            for(auto a:matrix[i]){
                ++indegree[a.data];
            }
        }

        for(int i=0;i<n;++i){
            if(indegree[i]==0){
                s.insert(i);
            }
        }

        while(!s.empty()){
            temp=*s.begin();
            s.erase(s.begin());
            cout<<temp+1<<" ";
            for(auto a:matrix[temp]){
                if(--indegree[a.data]==0){
                    s.insert(a.data);
                }
            }
        }
        cout<<endl;
    }

    return 0;
}