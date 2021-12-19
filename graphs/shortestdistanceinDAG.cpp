#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int *dis;
vector <pair<int,int>> *adj;
void bfs(int j){
        queue <int> q;
        q.push(j);
        dis[j] = 0;
        while(!q.empty()){
                int k = q.front();
                q.pop();
                for(int i=0;i<adj[k].size();i++){
                        if(dis[adj[k][i].first] > dis[k]+adj[k][i].second){
                                cout<<"updated!!"<<endl;
                                dis[adj[k][i].first]=adj[k][i].second+dis[k];
                                q.push(adj[k][i].first);
                                
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
        adj = new vector<pair<int,int>>[n];
        for(int i=0;i<m;i++){
                int a,b,c;
                cin>>a>>b>>c;
                adj[a].push_back({b,c});
        }
        int src;
        cin>>src;
        bfs(src);
        for(int i=0;i<n;i++){
                cout<<"distance for "<<i<<" is "<<dis[i]<<endl;
        }
        
}