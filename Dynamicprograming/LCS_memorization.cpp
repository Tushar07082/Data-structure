#include <iostream>
#include <vector>
using namespace std;
vector<int> *t;
int lCS(string s1, string s2,int n,int m){
        if(n==0 || m==0){
                return 0;
        }
        if(t[n][m] != -1){
                return t[n][m];
        }
        if(s1[n-1] == s2[m-1]){
                return t[n][m] = 1+lCS(s1,s2,n-1,m-1);
        }
        else return t[n][m] = max(lCS(s1,s2,n-1,m),lCS(s1,s2,n,m-1));
}
int main(){
        string s1,s2;
        int n,m;
        cin>>s1;
        
        cin>>s2;
        
        n = s1.size();
        
        m = s2.size();
        
        t = new vector<int> [n+1];
        
        for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                        if(i==0 || j==0){
                                t[i].push_back(0);
                        }else {
                                t[i].push_back(-1);
                        }
                        
                }
        }
        for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                        cout<<t[i][j]<<" ";
                }
                cout<<endl;
        }
        cout<<lCS(s1, s2,n,m);
}