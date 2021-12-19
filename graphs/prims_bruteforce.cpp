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

int main(){
        int n,m;
        cin>>n>>m;
        adj = new vector<pair<int,int>>[n];
        for(int i=0;i<m;i++){
                int a,b,c;
                cin>>a>>b>>c;
                adj[a].push_back({b,c});
                adj[b].push_back({a,c});
        }
        vector <int> key(n,INT_MAX);
        vector <int> parent(n,-1);
        vector <bool> mstset(n,false);
        key[0]=0;
        for(int count =0;count<n-1;count++){
                int mini = INT_MAX,v;
                for(int i=0;i<n;i++){
                        if(mstset[i]==false && mini > key[i]){
                                mini = key[i];
                                v = i;
                        }
                }
                mstset[v] = true;
                for(int i=0;i<adj[v].size();i++){
                        int k = adj[v][i].first;
                        int weight = adj[v][i].second;
                        if(mstset[k]==false && key[k]>weight){
                                key[k]= weight;
                                parent[k] = v;
                        }
                }

        }
        for(int i=1;i<n;i++){
                cout<<parent[i]<<"->"<<i<<endl;
        }
        
}