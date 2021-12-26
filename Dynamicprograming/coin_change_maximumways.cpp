#include <iostream>
using  namespace std;
int change(int a,int coins[],int n){
        int t[n+1][a+1];
        for(int i=0;i<=n;i++){
                
                for(int j=0;j<=a;j++){
                        if(j==0){
                                t[i][j] = 1;
                        }else if(i==0){
                                t[i][j] = 0;
                        }
                        else if(coins[i-1]>j){
                                t[i][j] = t[i-1][j];
                        }
                        else{
                                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                        
                        }
                }
        }
        for(int i=0;i<=n;i++){
                if(i!=0){
                        cout<<"element is "<<coins[i-1]<<endl;
                }
                for(int j=0;j<=a;j++){
                        cout<<t[i][j]<<" ";
                }
                cout<<endl;
        }
        return t[n][a];

}
int main(){
        int n,a;
        cin>>n>>a;
        int coins[n];
        for(int i=0;i<n;i++){
                cin>>coins[i];
        }
        
        cout<<change(a,coins,n);
}