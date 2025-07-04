#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define int long long

int32_t main() {
    FAST
    int n;
    cin>>n;
    vector<int> a(n);
    for(int& x:a)cin>>x;
    vector<int> dp;
    for(int x:a){
        auto lb=lower_bound(dp.begin(),dp.end(),x);
        if (lb==dp.end()) {
            dp.push_back(x);
        } else {
            *lb = x;
        }
    }
    cout<<dp.size()<<'\n';
    return 0;
}
