#include <iostream>
using namespace std;
int main(){
        int n,w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        int t[n+1][w+1];
        for(int i=0;i< n;i++){
                cin>>val[i];
        }
        for(int i=0;i< n;i++){
                cin>>wt[i];
        }
        for(int i=0;i<n+1;i++){
                for(int j=0;j<w+1;j++){
                        if(j==0 || i==0){
                                t[i][j] =0;
                        }
                        else{
                                if(wt[i-1]<=j){
                                        t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                                }else{
                                        t[i][j] = t[i-1][j];
                                }
                        }
                }
        }
        cout<<t[n][w];
        
}