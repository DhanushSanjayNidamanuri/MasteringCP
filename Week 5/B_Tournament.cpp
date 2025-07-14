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

void solve() {
    // your logic here
    int n,p,k;
    cin>>n>>p>>k;;
    int a;
    p--;
    vector<int> arr(n);
    int max=0;
    for(int i=0;i<n;i++){cin>>arr[i];if(arr[i]>max)max=arr[i];}
    if(k>=2)cout<<"YES\n";
    else{
        if(arr[p]==max)cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
