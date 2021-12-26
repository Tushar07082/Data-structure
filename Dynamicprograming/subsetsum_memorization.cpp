#include <iostream>
#include <vector>
using namespace std;
vector <int> *t;
int issubsetsum(int n,int arr[],int sum){
        if(n==0){
                if(sum ==0){
                        return true;
                }
                return false;
        }
        if(t[n][sum] != -1){
                return t[n][sum];
        }
        if(sum < arr[n-1]){
                return t[n][sum] = issubsetsum(n-1,arr,sum);
        }
        else{
                return t[n][sum] = issubsetsum(n-1,arr,sum-arr[n-1])|| issubsetsum(n-1,arr,sum);
        }
}
int main(){
        int n,sum;
        cin>>n;
        int arr[n];
        t = new vector<int>[n+1];
        for(int i=0;i<n;i++){
                cin>>arr[i];
        }
        cin>>sum;
        for (int i = 0; i < n + 1; i++)
        {
                for (int j = 0; j < sum + 1; j++)
                {
                        if (i == 0)
                        {
                                t[i].push_back(0);
                        }
                        else
                                t[i].push_back(-1);
                }
        }
        cout<<issubsetsum(n,arr,sum);
}