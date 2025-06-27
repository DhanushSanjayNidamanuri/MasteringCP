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
    int k=0,i,step;int power;
    int p,q;
    cin>>p;
    for(int r=1;r<n;r++){
        cin>>q;
        if(q<p){
            power=0;step=p-q;
            while(step>0){
                step/=2;power++;
            }
            if(power>k)k=power;
            q=p;
        }
        p=q;
    }
    cout<<k<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
