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
    int n,x;
    cin>>n>>x;
    int k=__builtin_popcount(x);
    if(n<=k) cout<<x<<"\n";
    else{
    int i=0,sum=x;
    int t=(x&1);
    while(k!=n && i<32){
        int p=min((n-t)/2,(n-k)/2);
        t+=p*2;k+=p*2;sum+=p*(1<<(i+1));
        if(t+2<=n && k+1<=n){t+=2;k++;sum+=(1<<(i+1));}
            i++;t=bool(x&(1<<i));
    }; 
    if(n==k)cout<<sum<<"\n";
    else{cout<<"-1\n";}
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
