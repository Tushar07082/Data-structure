#include <iostream>
#include <vector>
using namespace std;

string printSCS(string s1, string s2,int n,int m){
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
                t[i][0] = 0;
        }
        for(int i=0;i<= m;i++){
                t[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        if(s1[i-1] == s2[j-1]){
                                t[i][j] = 1+ t[i-1][j-1];
                        }
                        else{
                                t[i][j] = max(t[i][j-1] , t[i-1][j]);
                                
                        }
                }
        }
        int i=n,j=m;
        string ans = "";
        while(i!=0 && j!=0){
                if(i!=0 && j!=0 && s1[i-1] == s2[j-1]){
                        ans += s1[i-1];
                        i--;
                        j--;
                }else{
                        if(i!=0 && j!=0 && t[i][j-1] > t[i-1][j]){
                                ans += s2[j-1];
                                j--;
                        }else{
                                ans += s1[i-1];
                                i--;
                        }
                        
                }
        }
        while(i!=0){
                ans += s1[i-1];
                        i--;
        }
        while(j!=0){
                ans += s2[j-1];
                        j--;
        }
        string SCS= "";
        for(int i=ans.size()-1;i>=0;i--){
                SCS += ans[i];
        }
        
        return SCS;
}
int main(){
        string s1,s2;
        int n,m;
        cin>>s1;
        
        cin>>s2;
        
        n = s1.size();
        
        m = s2.size();
        
        
        cout<<printSCS(s1, s2,n,m);
}