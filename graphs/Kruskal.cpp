#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int *parent;
int *ranki;
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

int findpar(int i){
        if(parent[i]==i){
                return i;
        }
        parent[i] = findpar(parent[i]);
        return parent[i];
}
void unionn(int a,int b){
        a = findpar(a);
        b = findpar(b);
        if(ranki[a]<ranki[b]){
                parent[a] = b;
        }
        else if(ranki[b]<ranki[a]){
                parent[b] = a;
        }
        else {
                parent[a] = b;
                ranki[b] ++;
        }

}
bool comp(node a,node b){
        return a.wt<b.wt;
}
int main(){
        int n,m;
        cin>>n>>m;
        vector <node> edges;
        for(int i=0;i<m;i++){
                int a,b,c;
                cin >> a >> b >> c;
                edges.push_back({a,b,c});
        }
        parent = new int[n];
        for(int i=0;i<n;i++){
                parent[i] = i;
        }
        ranki = new int[n]{0};
        vector<pair<int,int>> mst;
        int cost =0;
        sort(edges.begin(),edges.end(),comp);
        for(int i=0;i<m;i++){
                if(findpar(edges[i].u) != findpar(edges[i].v)){
                        cost+= edges[i].wt;
                        mst.push_back({edges[i].u,edges[i].v});
                        unionn(edges[i].u,edges[i].v);
                }
        }
        for(int i=0;i<n-1;i++){
                cout<<mst[i].first<<"->"<<mst[i].second<<endl;
        }
}