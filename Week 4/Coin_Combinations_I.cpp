#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(0); cin.tie(0);

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
    int n,x;
    const int MOD=1e9+7;
    cin>>n;cin>>x;
    vector<int> coins(n);
    vector<int> calculated(x+1,0);
    calculated[0]=1;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    for(int i=1;i<=x;i++){
            for (int j = 0; j < n; ++j) {
                int c = coins[j];
                if (i - c < 0) break;
                calculated[i] = (calculated[i] + calculated[i - c]) % MOD;
            };
        }
    cout<<calculated[x];
}