#include <iostream>
#include <limits.h>
using namespace std;
int mcm(int a[],int i,int j){
        if(i>=j){
                return 0;
        }
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
                int x = mcm(a,i,k);
                int y = mcm(a,k+1,j);
                int tempans = a[i-1]*a[k]*a[j] + x+ y;
                mini = min(mini,tempans);
        }
        return mini;
}
int main(){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
                cin>>a[i];
        }
        cout<<mcm(a,1,n-1);
}