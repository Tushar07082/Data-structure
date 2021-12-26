#include <bits/stdc++.h>
using namespace std;
bool equalPartition(int n,int arr[],int sum){
        if(n==0){
                if(sum == 0){
                        // cout<<sum1<<" "<<sum2;
                        return true;
                }else return false;
        }
        if(arr[n-1]>sum){
                return equalPartition(n-1,arr,sum);
        }
        return equalPartition(n-1,arr,sum)||equalPartition(n-1,arr,sum-arr[n-1]);
        

}
int main(){
        int n;
        cin>>n;
        int a[n],sum=0;
        for(int i=0;i<n;i++){
                cin>>a[i];
                sum+= a[i];
        }
        if(sum%2){
                cout<<0;
                return true;
        }
        cout<<equalPartition(n,a,sum/2);
}