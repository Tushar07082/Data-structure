#include <iostream>
#include <queue>
using namespace std;
int *vis;
vector <int> *adj;
bool cycledfs(int i,int parent){
       cout<<i<<" ";
       for(int j=0;j<adj[i].size();j++){
               if(!vis[adj[i][j]]){
                       vis[adj[i][j]] = 1;
                       if(cycledfs(adj[i][j],i)){
                               return true;
                       }
               }
               else if(vis[adj[i][j]]==1 && adj[i][j] != parent){
                       return true;
               }
       }
       return false;
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
                        if(cycledfs(i,-1)){
                                cout<<"Cycle detected!";
                                return 0;
                        }
                }
        }
        cout<<"Acylic Graph!";
        
}