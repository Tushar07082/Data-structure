#include <iostream>
using  namespace std;
int cutRod(int price[],int n){
        int t[n+1][n+1];
        for(int i=0;i<=n;i++){
                
                for(int j=0;j<=n;j++){
                        if(i==0||j==0){
                                t[i][j] =0;
                        }
                        else if(i >j){
                                t[i][j] = t[i-1][j];
                        }
                        else{
                                t[i][j] = max(price[i-1]+ t[i][j-i],t[i-1][j]);
                        }
                }
        }
        for(int i=0;i<=n;i++){
                if(i!=0){
                        cout<<"element is "<<price[i-1]<<endl;
                }
                for(int j=0;j<=n;j++){
                        cout<<t[i][j]<<" ";
                }
                cout<<endl;
        }
        return t[n][n];

}
int main(){
        int n;
        cin>>n;
        int price[n];
        for(int i=0;i<n;i++){
                cin>>price[i];
        }
        
        cout<<cutRod(price,n);
}