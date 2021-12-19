#include <iostream>
#include <queue>
using namespace std;
int *vis;
vector <int> *adj;

bool cyclebfs(int j){
        queue <pair<int,int>> q;
        q.push({j,-1});
        vis[j] = 1;
        while(!q.empty()){
                int k = q.front().first;
                int parent = q.front().second;
                q.pop();
                cout<<k<<" ";
                for(int i=0;i<adj[k].size();i++){
                        if(!vis[adj[k][i]]){
                                q.push({adj[k][i],k});
                                vis[adj[k][i]]=1;
                        }
                        else if(vis[adj[k][i]]==1 && adj[k][i] != parent){
                                return true;
                        }
                }

        }
        cout<<endl;
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
                        if(cyclebfs(i)){
                                cout<<"Cycle detected!";
                                return 0;
                        }
                }
        }
        cout<<"Acylic Graph!";

        
}