#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int *dis;

struct node{
        int u;
        int v;
        int wt;
        node(int f,int s,int w){
                u = f;
                v = s;
                wt = w;
        }
};
vector <node> edges;
int n,m;
vector <pair<int,int>> *adj;

void bellmanford(int j){
        for(int i=0;i<n;i++){
                dis[i] = 1999999;
        }
        dis[j] =0;
        for(int i=0;i<n-1;i++){
                for(int j=0;j<m;j++){
                        if(dis[edges[j].u] + edges[j].wt < dis[edges[j].v]){
                                dis[edges[j].v] = dis[edges[j].u] + edges[j].wt;
                        }
                }
        }
}
int main(){
       
        cin>>n>>m;
        dis = new int[n];
        for(int i=0;i<m;i++){
                int a,b,c;
                cin >> a >> b >> c;
                edges.push_back({a,b,c});
        }
        int src;
        cin>>src;
        bellmanford(src);
        for(int i=0;i<n;i++){
                cout<<"distance for "<<i<<" is "<<dis[i]<<endl;
        }
        
}