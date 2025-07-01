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
const int MOD=1e9+7;

void solve() {
    // your logic here
    int n;
    cin>>n;
    int a=1,b=1;
    int temp1,temp2;
    for(int i=1;i<n;i++){temp1=a;temp2=b;a=4*temp1+temp2;b=temp1+2*temp2;a%=MOD;b%=MOD;}
    cout<<(a+b)%MOD<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
