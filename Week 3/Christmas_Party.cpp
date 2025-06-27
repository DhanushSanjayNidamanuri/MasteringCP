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
int MOD=1e9+7;
void solve() {
    // your logic here
    int n,m,out=0,i,fact=1;
    cin>>n;
    if(n%2==0)m=1;
    else m=-1;
    for(int i=0;i<n-1;i++,m*=-1){  
        out+=m*fact;
        out%=MOD;
        fact=fact*(n-i) %MOD;
    }
    out=(out+MOD)%MOD;
    cout<<out;
}

int32_t main() {
    FAST
    solve();
    return 0;
}
