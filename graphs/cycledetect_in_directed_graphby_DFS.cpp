#include <iostream>
#include <queue>
using namespace std;
int *vis,*dfsvis;
vector <int> *adj;
bool cycledfs(int i,int parent){
       cout<<i<<" ";
       for(int j=0;j<adj[i].size();j++){
               if(!vis[adj[i][j]]){
                       vis[adj[i][j]] = 1;
                       dfsvis[adj[i][j]]=1;
                       if(cycledfs(adj[i][j],i)){
                               return true;
                       }
               }
               else if(vis[adj[i][j]]==1 && adj[i][j] != parent){
                       if(dfsvis[adj[i][j]]==1){
                               return true;
                       }
               }
       }
       dfsvis[i] = 0;
       return false;
}
int main(){
        int n,m; 
        cin>>n>>m;
        vis = new int[n]{};
        dfsvis = new int[n]{};
        adj = new vector<int>[n];
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a].push_back(b);
        }
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        vis[i]=1;
                        dfsvis[i]=1;
                        if(cycledfs(i,-1)){
                                cout<<"Cycle detected!";
                                return 0;
                        }
                }
        }
        cout<<"Acylic Graph!";
        
}