#include <bits/stdc++.h>
using namespace std;
vector<int> *t;
bool equalpartition(int n,int arr[],int sum){
        if(n==0){
                if(sum == 0){
                        return true;
                }else return false;
        }
        if(t[sum][n] != -1){
                return t[sum][n];
        }
        if(arr[n-1]>sum){
                return equalpartition(n-1,arr,sum);
        }
        return t[sum][n] = equalpartition(n-1,arr,sum-arr[n-1])||equalpartition(n-1,arr,sum);
        

}
int main(){
        int n;
        cin>>n;
        int a[n],sum=0;
        for(int i=0;i<n;i++){
                cin>>a[i];
                sum+= a[i];
        }
        t = new vector<int>[sum+1];
        for(int i=0;i<sum+1;i++){
                for(int j=0;j<n+1;j++){
                        if(i==0 && j==0){
                                t[i].push_back(1);
                        }
                        else if(j==0){
                                t[i].push_back(0);
                        }
                        else t[i].push_back(-1);
                }
        }
        if(sum%2){
                cout<<0;
            return 0;
        }
        cout<<equalpartition(n,a,sum/2);
}