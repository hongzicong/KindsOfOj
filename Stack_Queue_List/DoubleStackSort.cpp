#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool flag=true;
int color[1000];
int graph[1000][1000];
int v[1000];
int n;
vector<char> o;

void setColor(int i,int c){
    color[i]=c;
    for(int j=0;j<n;++j){
        if(graph[i][j]){
            if(color[i]==color[j]){
                flag=false;
            }
            if(!color[j]){
                setColor(j,(c==1)?2:1);
            }
        }
    }
}

void createGraph(void){
    for(int i=0;i<n-2;++i){
        for(int j=i+1;j<n-1;++j){
            for(int k=j+1;k<n;++k){
                if(v[j]>v[i]&&v[i]>v[k]){
                    graph[i][j]=graph[j][i]=1;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        if(!color[i]){
            setColor(i,1);
        }
    }
}

void calculate(void){
    if(flag==false){
        cout<<0<<endl;
        return;
    }
    stack<int> s1;
    stack<int> s2;
    int count=0;
    int curr=1;
    for(int i=0;i<n;++i){
        if(color[i]==1){
            s1.push(v[i]);
            cout<<"a";
            count++;
            if (count < n*2) {
                cout << " ";
            }
        } else if(color[i]==2){
            s2.push(v[i]);
            cout<<"c";
            count++;
            if (count < n*2) {
                cout << " ";
            }
        }

        while((!s1.empty()&&s1.top()==curr)||(!s2.empty()&&s2.top()==curr)){
            if(!s1.empty()&&s1.top()==curr){
                s1.pop();
                cout<<"b";
                count++;
                if (count < n*2) {
                    cout << " ";
                }
                curr++;
            }
            else{
                s2.pop();
                cout<<"d";
                count++;
                if (count < n*2) {
                    cout << " ";
                }
                curr++;
            }
        }

    }
    cout<<endl;
}

int main(void){

    while(cin>>n){
        flag=true;
        for(int i=0;i<1000;++i){
            color[i]=0;
            for(int j=0;j<1000;++j){
                graph[i][j]=0;
            }
        }
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        createGraph();
        calculate();
    }

    return 0;
}