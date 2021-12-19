#include <iostream>
#include <stack>
#include <limits.h>
#include <vector>
using namespace std;
int *vis;
vector <pair<int,int>> *adj;
stack <int> st;
void toposort(int i){
        vis[i]=1;
        int k = adj[i].size();
        for(int j=0;j<k;j++){
                if(!vis[adj[i][j].first]){
                        cout<<i<<" calls "<<adj[i][j].first<<endl;
                       toposort(adj[i][j].first); 
                }
        }
        cout<<i<<" call ended!\n";
        st.push(i);
}
int main(){
        int n,m;
        cin>>n>>m;
        vis = new int[n]{};
        adj = new vector<pair<int,int>>[n];
        for(int i=0;i<m;i++){
                int a,b,c;
                cin>>a>>b>>c;
                adj[a].push_back({b,c});
        }
        int src;
        cin>>src;
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        
                        toposort(i);
                }
        }
        int dis[n];
        for(int i=0;i<n;i++){
                dis[i] = INT_MAX;
        }
        dis[src] = 0;
        while(!st.empty()){
                int k = st.top();
                st.pop();
                if(dis[k] != INT_MAX){
                        for(int i=0;i<adj[k].size();i++){
                                if(dis[adj[k][i].first] > dis[k]+adj[k][i].second){
                                        dis[adj[k][i].first] = dis[k]+adj[k][i].second;
                                }
                        }
                }
        }
        for(int i=0;i<n;i++){
                cout<<"distance for "<<i<<" is "<<dis[i]<<endl;
        }

}