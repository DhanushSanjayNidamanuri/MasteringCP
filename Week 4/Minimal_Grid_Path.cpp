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
    vector<vector<int>> counts(n,vector<int>(n,-1));
    vector<vector<char>> states(n,vector<char>(n,true));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>states[i][j];
        }
    }
    int i=0,j=0;
    cout<<states[0][0];
    while(i<n || j<n){
        if(states[i+1][j]>states[i][j+1])
    }
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
