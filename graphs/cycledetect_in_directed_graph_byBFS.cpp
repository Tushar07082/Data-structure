#include <iostream>
#include <queue>
using namespace std;
int *vis;
vector <int> *adj;
int *indegree;
int count =0;
void bfs(int j){
        queue <int> q;
        q.push(j);
        vis[j] = 1;
        while(!q.empty()){
                int k = q.front();
                q.pop();
                count++;
                cout<<k<<" ";
                for(int i=0;i<adj[k].size();i++){
                        indegree[adj[k][i]]--;
                        if(!vis[adj[k][i]] && indegree[adj[k][i]]==0){
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
        indegree = new int[n]{};
        adj = new vector<int>[n];
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a].push_back(b);
                indegree[b]++;
        }
        for(int i=0;i<n;i++){
                if(!vis[i] && indegree[i]==0){
                        bfs(i);
                }
        }
        cout<<endl;
        if(count==n){
                cout<<"No cycle!";
        }else cout<<"Cycle detected!!";

        
}