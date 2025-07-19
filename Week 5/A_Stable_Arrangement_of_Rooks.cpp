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
    int n,k;
    cin>>n>>k;
    if(k>((n+1)/2))cout<<"-1\n";
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (i == j && i % 2 == 0 && k > 0) {
                    cout << "R";
                    --k;
                }
                else cout<<".";
            }
            cout<<"\n";        }
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
