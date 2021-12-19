#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int *vis;
vector <int> *adj;
stack <int> st;
vector <int> *trans;
void dfs(int i){
        vis[i]=1;
        int k = adj[i].size();
        for(int j=0;j<k;j++){
                if(!vis[adj[i][j]]){
                        cout<<i<<" calls "<<adj[i][j]<<endl;
                       dfs(adj[i][j]); 
                }
        }
        cout<<i<<" call ended!\n";
        st.push(i);
}
void secdfs(int i){
        cout<<i<<" ";
        vis[i]=1;
        int k = trans[i].size();
        for(int j=0;j<k;j++){
                if(!vis[trans[i][j]]){
                        // cout<<i<<" calls "<<trans[i][j]<<endl;
                       secdfs(trans[i][j]); 
                }
        }
        // cout<<i<<" call ended!\n";
}
int main(){
        int n,m;
        cin>>n>>m;
        adj = new vector <int>[n];
        vis = new int[n]{};
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                adj[a].push_back(b);
        }
        // for(int i=0;i<n;i++){
        //         cout<<i<<":";
        //         for(auto j:adj[i]){
        //                 cout<<j<<" ";
        //         }
        //         cout<<endl;
        // }
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        
                        dfs(i);
                }
        }
        cout<<endl;
        
        trans = new vector<int>[n];
        for(int i=0;i<n;i++){
                vis[i] =0;
                for(int j=0;j<adj[i].size();j++){
                        trans[adj[i][j]].push_back(i);
                }
        }
        // for(int i=0;i<n;i++){
        //         // vis[i] =0;
        //         cout<<i<<"->";
        //         for(int j=0;j<trans[i].size();j++){
        //                 cout<<trans[i][j];
        //         }
        //         cout<<endl;
        // }
        // for(int i=0;i<n;i++){
                
        // }
        while(!st.empty()){
                int k = st.top();
                st.pop();
                if(!vis[k]){
                        secdfs(k);
                        cout<<endl;
                }
        }


}