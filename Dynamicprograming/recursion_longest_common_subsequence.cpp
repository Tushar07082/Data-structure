#include <iostream>
using namespace std;
int lCS(string s1, string s2,int n,int m){
        if(n==0 || m==0){
                return 0;
        }
        if(s1[n-1] == s2[m-1]){
                return 1+lCS(s1,s2,n-1,m-1);
        }
        else return max(lCS(s1,s2,n-1,m),lCS(s1,s2,n,m-1));
}
int main(){
        string s1,s2;
        cin>>s1>>s2;
        cout<<lCS(s1, s2,s1.size(),s2.size());
}