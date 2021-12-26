#include <limits.h>
#include <iostream>
using  namespace std;
int coinChange(int coins[],int a,int n){
        int t[n+1][a+1];
        for(int i=0;i<=n;i++){
                
                for(int j=0;j<=a;j++){
                        if(j==0){
                                t[i][j] = 0;
                        }else if(i==0){
                                t[i][j] = INT_MAX-1;
                        }
                        else if(i==1){
                                if(j%coins[i-1] == 0){
                                        t[i][j] = min(j/coins[i-1],min(1+ t[i][j-coins[i-1]],t[i-1][j]));
                                }else {
                                        t[i][j] = INT_MAX-1;
                                }
                        }
                        else if(coins[i-1]>j){
                                t[i][j] = t[i-1][j];
                        }
                        else{
                                if(j%coins[i-1] == 0){
                                        t[i][j] = min(j/coins[i-1],min(1+ t[i][j-coins[i-1]],t[i-1][j]));;
                                }else{
                                        t[i][j] =min(1+ t[i][j-coins[i-1]],t[i-1][j]);
                                }
                        
                        }
                }
        }
        // for(int i=0;i<=n;i++){
        //         if(i!=0){
        //                 cout<<"element is "<<coins[i-1]<<endl;
        //         }
        //         for(int j=0;j<=a;j++){
        //                 cout<<t[i][j]<<" ";
        //         }
        //         cout<<endl;
        // }
        int x = INT_MAX;
        for(int i=0;i<=n;i++){
                if(t[i][a] < x){
                        x = t[i][a];
                }
        }
        if(x == INT_MAX-1){
                return -1;
        }
        return x;

}
int main(){
        int n,a;
        cin>>n>>a;
        int coins[n];
        for(int i=0;i<n;i++){
                cin>>coins[i];
        }
        
        cout<<coinChange(coins,a,n);
}