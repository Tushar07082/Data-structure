#include <iostream>
#include <queue>
using namespace std;
int *vis;
vector <int> *adj;
void dfs(int i){
       cout<<i<<" ";
       for(int j=0;j<adj[i].size();j++){
               if(!vis[adj[i][j]]){
                       vis[adj[i][j]] = 1;
                       dfs(adj[i][j]);
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
                        vis[i] =1;
                        dfs(i);
                }
        }

        
}