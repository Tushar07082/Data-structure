#include <iostream>
#include <queue>
using namespace std;
int *color;
vector <int> *adj;

bool isbipartite(int j){
        queue <int> q;
        q.push(j);
        while(!q.empty()){
                int k = q.front();
                q.pop();
                cout<<k<<" ";
                for(int i=0;i<adj[k].size();i++){
                        // cout<<"color of "<<adj[k][i]<<" is "<<color[adj[k][i]]<<endl;
                        if(color[adj[k][i]]==-1){
                                if(color[k]==0){
                                        color[adj[k][i]]=1;
                                }else color[adj[k][i]]=0;
                                q.push(adj[k][i]);
                        }else if(color[adj[k][i]]==color[k]){
                                return false;
                        }
                }

        }
        cout<<endl;
        return true;
}
int main(){
        int n,m;
        cin>>n>>m;
        color = new int[n];
        for(int i=0;i<n;i++){
                color[i]=-1;
        }
        adj = new vector<int>[n];
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
        }
        for(int i=0;i<n;i++){
                if(color[i]==-1){
                        color[i] = 0;
                        if(!isbipartite(i)){
                                
                                cout<<"Not a bipartite";
                                return 0;
                        }
                }
        }
        cout<<"A pure bipartite graph";

        
}