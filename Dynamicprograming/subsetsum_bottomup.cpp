#include <iostream>
#include <vector>
using namespace std;
vector<int> *t;

int main()
{
        int n, sum;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
                cin >> arr[i];
        }
        cin >> sum;
        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
                for (int j = 0; j < sum + 1; j++)
                {
                        if (j == 0)
                        {       
                                
                                t[i][j] =1;
                        }
                        else if(i==0){
                                t[i][j] =0;
                        }
                        else
                        {
                                if (j < arr[i - 1])
                                {
                                        t[i][j] = t[i - 1][j];
                                }
                                else
                                {
                                        t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
                                }
                        }
                }
        }

        cout << t[n][sum];
}