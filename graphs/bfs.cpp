#include <iostream>
#include <queue>
using namespace std;
int *vis;
vector <int> *adj;
void bfs(int j){
        queue <int> q;
        q.push(j);
        vis[j] = 1;
        while(!q.empty()){
                int k = q.front();
                q.pop();
                cout<<k<<" ";
                for(int i=0;i<adj[k].size();i++){
                        if(!vis[adj[k][i]]){
                                q.push(adj[k][i]);
                                vis[adj[k][i]]=1;
                        }
                }

        }
}
int main(){
        int n,m;
        cin>>n>>m;
        vis = new int[n]{};
        adj = new vector<int>[n];
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
        }
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        bfs(i);
                }
        }

        
}