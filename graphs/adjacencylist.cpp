#include <iostream>
#include <vector>
using namespace std;
int main(){
        int n,m;
        cout<<"enter the number of vertices and number of edges:\n";
        cin>>n>>m;
        vector<int> arr[n];
        cout<<"enter all edges:\n";
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                arr[a].push_back(b);
                arr[b].push_back(a);
        }
        for(int i=0;i<n;i++){
                cout<<i<<":";
                for(auto j:arr[i]){
                        cout<<j<<" ";
                }
                cout<<endl;
        }
}