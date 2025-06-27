#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define ll long long

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
}

int32_t main() {
    FAST
    ll n,m;
    cin>>n>>m;
    long long k=(n-n%m)/m;
    ll min,max;
    if(k==1)min=((n%m)*(k+1)*(k))/2;
    else min=(((n%m)*(k+1)*(k))/2)+(((m-(n%m))*k*(k-1))/2);
    if(n==m)max=min;
    else max=((n-m+1)*(n-m))/2;
    cout<<min<<" "<<max;

}
