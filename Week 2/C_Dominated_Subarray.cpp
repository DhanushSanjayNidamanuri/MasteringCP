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
    int n;
    cin>>n;
    int out=n+1,a;
    map<int,int> pos;
    for(int i=0;i<n;i++){
        cin>>a;        
        if(pos[a]!=0)out=min(out,(i+1)-pos[a]+1);
        pos[a]=i+1;
    }
    if(out==n+1)cout<<"-1"<<"\n";
    else cout<<out<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
