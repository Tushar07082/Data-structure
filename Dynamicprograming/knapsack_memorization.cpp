#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> *t;

int profit(int w, int wt[], int val[], int n)
{
        if (n == 0 || w == 0)
        {
                return 0;
        }
        if(t[w][n] != -1){
                return t[w][n];
        }
        if(wt[n]>w){
            return t[w][n] = profit(w,wt,val,n-1);
        }
        else{
            return t[w][n] = max(val[n]+profit(w-wt[n],wt,val,n-1),profit(w,wt,val,n-1));
        }
}
int main()
{
        int n, w;
        cin >> n >> w;
        int val[n];
        int weight[n];
        t = new vector<int>[w + 1];
        for (int i = 0; i < w + 1; i++)
        {
                for (int j = 0; j < n + 1; j++)
                {
                        if (i == 0)
                        {
                                t[i].push_back(0);
                        }
                        else
                                t[i].push_back(-1);
                }
        }

        for (int i = 0; i < n; i++)
        {
                cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
                cin >> weight[i];
        }
        cout << profit(w, weight, val, n-1);
}