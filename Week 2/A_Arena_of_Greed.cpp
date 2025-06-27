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
    int n;
    cin>>n;
    int k=0;
    while(n>0){
        if(n%2==0 && n%4!=0){
            k+=n/2;n/=2;
            
        }
        else{
            n-=1;k++;
        }
        if(n%2==0 && n%4!=0){
            n/=2;
            
        }
        else{
            n-=1;
        }
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
