#include <iostream>
#include <vector>
using namespace std;

int lCS(string s1,int n){
        string s2="";
        for(int i=n-1;i>=0;i--){
                s2+= s1[i];
        }
        int t[n+1][n+1];
        for(int i=0;i<=n;i++){
                t[i][0] = 0;
        }
        for(int i=0;i<= n;i++){
                t[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        if(s1[i-1] == s2[j-1]){
                                t[i][j] = 1+ t[i-1][j-1];
                                
                        }
                        else{
                                t[i][j] = max(t[i][j-1] , t[i-1][j]);
                                
                        }
                }
        }
        
        return t[n][n];
}
int main(){
        string s1;
        int n;
        cin>>s1;
        n = s1.size();
        
        cout<<lCS(s1,n);
}