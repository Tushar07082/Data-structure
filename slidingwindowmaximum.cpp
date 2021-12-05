#include <bits/stdc++.h>
using namespace std;
int main(){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
                cin>>a[i];
        }
        multiset <int, greater<int>>p;
        vector<int> ans;
        for(int i=0;i<k;i++){
                p.insert(a[i]);
        }
        for(auto i:p)
        {
                cout<<i<<" ";
        }
        cout<<"\n";
        for(int i=k;i<n;i++){
                cout<<"Adding "<<*p.begin()<<" in answer"<<"\n";
                ans.push_back(*p.begin());
                p.erase(p.lower_bound(a[i-k]));
                cout<<"Adding "<<a[i]<<" in set"<<"\n";
                p.insert(a[i]);
        }
        ans.push_back(*p.begin());
        for(auto i: ans){
                cout<<i<<" ";
        }
        cout<<"\n";
}