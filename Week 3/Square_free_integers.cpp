#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define int unsigned long long

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
    cin>>n;
    vector<bool> arr(n+1,false);
    for(int i=2;i<=n;i++){
        if(!arr[i]){
            k=i*i;
            for(int j=i*i;j<=n;j+=k){
                arr[j]=true;
            }
        }
    }
    int out=0;
    for(int i=1;i<=n;i++){
        if(!arr[i]){
            out++;
        }
    }
    cout<<out<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
