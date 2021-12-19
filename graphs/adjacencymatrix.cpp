#include <iostream>
#include <vector>
using namespace std;
int main(){
        int n,m;
        cout<<"enter the number of vertices and number of edges:\n";
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(n,0));
        cout<<"enter all edges:\n";
        for(int i=0;i<m;i++){
                int a,b;
                cin>>a>>b;
                arr[a][b] = 1;
                arr[b][a] = 1;

        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        cout<<arr[i][j]<<" ";
                }
                cout<<endl;
        }
        

}