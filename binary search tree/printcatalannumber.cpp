#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        
        int a[n+1]={0};
        a[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j =0;j<i;j++){
                a[i] += a[j]*a[i-1-j];
            }
        }
        return a[n];
    }
};
int main(){
        Solution a;
        cout<<a.numTrees(19);
}
