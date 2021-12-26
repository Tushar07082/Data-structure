#include <iostream>
using namespace std;
int profit(int w,int wt[],int val[],int n){
        if(n==0 || w==0){
            return 0;
        }
        
        if(wt[n]>w){
            return profit(w,wt,val,n-1);
        }
        else{
            return max(val[n]+profit(w-wt[n],wt,val,n-1),profit(w,wt,val,n-1));
        }
}
int main(){
        int n,w;
        cin>>n>>w;
        int val[n];
        int weight[n];
        
        for(int i=0;i< n;i++){
                cin>>val[i];
        }
        for(int i=0;i< n;i++){
                cin>>weight[i];
        }
        cout<<profit(w,weight,val,n-1);
}