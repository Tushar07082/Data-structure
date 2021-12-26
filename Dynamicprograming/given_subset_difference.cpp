#include <iostream>
#include <vector>
using namespace std;
int range =0;
int difference(int a[],int n,int diff){
        for(int i=0;i<n;i++){
                range += a[i];
        }
        int k = (range-diff)/2;
        int t[n+1][k +1];
        
        for(int i=0;i<=n;i++){
                t[i][0] = 1;
        }
        for(int i=1;i<=k;i++){
                t[0][i] = 0;
        }
        for(int i=0;i<=n;i++){
                for(int j=0;j<=k;j++){
                        if(i==0 || j==0){
                                cout<<t[i][j]<<" ";
                        }
                        else if(a[i-1]>j){
                                t[i][j] = t[i-1][j];
                                cout<<t[i][j]<<" ";
                        }else{
                                t[i][j] = t[i-1][j] + t[i-1][j-a[i-1]];
                                cout<<t[i][j]<<" ";
                        }
                }
                cout<<endl;
        }
        return t[n][k];
        // cout<<i<<endl; 

}
int main(){
        int n;
        cin>>n;
        int a[n],diff;
        for(int i=0;i<n;i++){
                cin>>a[i];
        }
        cin>>diff;
        cout<<difference(a,n,diff);
}