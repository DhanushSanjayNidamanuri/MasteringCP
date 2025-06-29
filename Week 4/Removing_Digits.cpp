
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

int steps(int n,int k){
    if(n==0)return k;
    else{
        int testn=n,maxi=0;
        while(testn>0){
            maxi=max(maxi,testn%10);
            testn/=10;
        };
        return steps(n-maxi,k+1)
        ;
    }
}
void solve() {
    // your logic here
    int n;
    cin>>n;
    cout<<steps(n,0);
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
