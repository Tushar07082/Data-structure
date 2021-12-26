#include <iostream>
using  namespace std;
int knapSack(int N, int W, int val[], int wt[]){
        int t[N+1][W+1];
        for(int i=0;i<=N;i++){
                
                for(int j=0;j<=W;j++){
                        if(i==0||j==0){
                                t[i][j] =0;
                        }
                        else if(wt[i-1]>j){
                                t[i][j] = t[i-1][j];
                        }
                        else{
                                t[i][j] = max(val[i-1]+ t[i][j-wt[i-1]],t[i-1][j]);
                        }
                }
        }
        for(int i=0;i<=N;i++){
                if(i!=0){
                        cout<<"element is "<<val[i-1]<<endl;
                }
                for(int j=0;j<=W;j++){
                        cout<<t[i][j]<<" ";
                }
                cout<<endl;
        }
        return t[N][W];

}
int main(){
        int n,W;
        cin>>n>>W;
        int val[n],w[n];
        for(int i=0;i<n;i++){
                cin>>val[i];
        }
        for(int i=0;i<n;i++){
                cin>>w[i];
        }
        cout<<knapSack(n,W,val,w);
}