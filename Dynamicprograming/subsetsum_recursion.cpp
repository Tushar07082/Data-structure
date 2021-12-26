#include <iostream>
using namespace std;

bool issubsetsum(int n,int arr[],int sum){
        if(n==0){
                if(sum ==0){
                        return true;
                }
                return false;
        }
        if(sum < arr[n-1]){
                return issubsetsum(n-1,arr,sum);
        }
        else{
                return issubsetsum(n-1,arr,sum-arr[n-1]) || issubsetsum(n-1,arr,sum);
        }
}
int main(){
        int n,sum;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
                cin>>arr[i];
        }
        cin>>sum;
        cout<<issubsetsum(n,arr,sum);
}