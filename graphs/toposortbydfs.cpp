#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int *vis;
vector <int> *adj;
stack <int> st;
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
        while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
        }


}