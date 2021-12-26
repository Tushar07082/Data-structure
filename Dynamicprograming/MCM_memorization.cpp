#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
vector <int> * t;
int mcm(int a[],int i,int j){
        if(i>=j){
                return 0;
        }
        if(t[i][j] != -1){
                return t[i][j];
        }
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
                int x = mcm(a,i,k);
                int y = mcm(a,k+1,j);
                int tempans = a[i-1]*a[k]*a[j] + x+ y;
                mini = min(mini,tempans);
        }
        return t[i][j] = mini;
}
int main(){
        int n;
        cin>>n;
        int a[n];
        t = new vector<int>[n];
        for(int i=0;i<n;i++){
                cin>>a[i];
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(i>=j){
                                t[i].push_back(0);
                
                        }else t[i].push_back(-1);
                }
        }
        cout<<mcm(a,1,n-1);
}