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
    int a,m,q;
    cin>>a>>m>>q;
    vector<int> arr(a+1);
    for(int i=1;i<=a;i++)cin>>arr[i];
    int type,i,x,k;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>i>>x;
            arr[i]=x;
        }
        if(type==2){
            cin>>k;
            
        }
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}
