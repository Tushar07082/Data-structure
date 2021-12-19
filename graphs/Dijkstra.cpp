#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int *dis;
vector <pair<int,int>> *adj;
// bool operator < (const pair<int,int>& p1, const pair<int,int>& p2)
// {
//     return p1.second < p2.second;
// }
void dijkstra(int j){
        priority_queue <pair<int,int>,vector<pair<int,int> >, greater<pair<int,int>>> q;
        q.push({0,j});
        dis[j] = 0;
        while(!q.empty()){
                int k = (q.top()).second;
                cout<<k<<" "<<q.top().first<<" size is "<<q.size()<<endl;
                q.pop();
                for(int i=0;i<adj[k].size();i++){
                        if(dis[adj[k][i].first] > dis[k]+adj[k][i].second){
                                dis[adj[k][i].first]=adj[k][i].second+dis[k];
                                q.push({dis[adj[k][i].first],adj[k][i].first});
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
                adj[b].push_back({a,c});
        }
        int src;
        cin>>src;
        dijkstra(src);
        for(int i=0;i<n;i++){
                cout<<"distance for "<<i<<" is "<<dis[i]<<endl;
        }
        
}