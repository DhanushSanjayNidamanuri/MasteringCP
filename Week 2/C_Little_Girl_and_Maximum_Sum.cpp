#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define sz(x) (int)(x).size()
#define F first
#define S second

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = b-1; i >= a; --i)

using vi = vector<int>;
using pii = pair<int, int>;


int32_t main() {
    FAST
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];};
    vector<int> repi(n,0);
    int a,b;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        repi[a-1]++;
        if(b!=n)repi[b]--;
    }
    for(int i=1;i<n;i++){
        repi[i]+=repi[i-1];
    }
    sort(arr.begin(),arr.end());
    sort(repi.begin(),repi.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i]*repi[i];
    }
    cout<<sum;

    return 0;
}
