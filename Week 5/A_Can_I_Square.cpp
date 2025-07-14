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
    int n;
    cin>>n;
    int out=0,a;
    for(int i=0;i<n;i++){
        cin>>a;
        out+=a;
    }
    if(sqrt(out)-double(int32_t(sqrt(out)))==0)cout<<"YES\n";
    else cout<<"NO\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
