#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int *dis;
vector <int> *adj;
void bfs(int j){
        queue <int> q;
        q.push(j);
        dis[j] = 0;
        while(!q.empty()){
                int k = q.front();
                q.pop();
                for(int i=0;i<adj[k].size();i++){
                        if(dis[adj[k][i]] > dis[k]+1){
                                dis[adj[k][i]]=1+dis[k];
                                q.push(adj[k][i]);
                                
                        }
                }

        }
}
int main(){
        int n,m;
        cin>>n>>m;
        dis = new int[n]{};
        for(int i=0;i<n;i++){
                dis[i] = INT_MAX;
        }
        adj = new vector<int>[n];
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
        }
        int src;
        cin>>src;
        bfs(src);
        for(int i=0;i<n;i++){
                cout<<"distance for "<<i<<" is "<<dis[i]<<endl;
        }
        
}