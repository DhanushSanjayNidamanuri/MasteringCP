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
    int n;cin>>n;
    vector<int> arr(n+2),mins(n+2),maxs(n+2);
    int maxi=0,mini=1e6+1;
    for(int i=1;i<=n;i++){cin>>arr[i];if(arr[i]<mini)mini=arr[i];mins[i]=mini;}
    for(int i=n;i>=1;i--){if(arr[i]>maxi)maxi=arr[i];maxs[i]=maxi;}
    for(int i=1;i<=n;i++){
        if((arr[i]==mins[i])||(arr[i]==maxs[i]))cout<<1;
        else cout<<0;
    }
    cout<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
