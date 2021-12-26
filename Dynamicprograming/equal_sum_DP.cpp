#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int> &nums)
{
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
                sum += nums[i];
        }
        if (sum % 2 != 0)
        {
                return false;
        }
        int t[n + 1][sum / 2 + 1];
        for (int i = 0; i <= n; i++)
        {
                t[i][0] = true;
        }
        for (int i = 1; i <= sum/2; i++)
        {
                t[0][i] = false;
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=sum/2;j++){
                        if(nums[i-1]> j){
                                t[i][j] = t[i-1][j];
                        }
                        else {
                                t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                        }
                }
        }
        return t[n][sum];
}

int main()
{
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }
        cout << canPartition(a);
}