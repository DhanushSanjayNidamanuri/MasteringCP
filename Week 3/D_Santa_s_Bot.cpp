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
int MOD=998244353;
int inv(int x) { return x <= 1 ? x : MOD -((( MOD / x )* inv(MOD % x)) % MOD); }

void solve() {
    // your logic here
    int n;
    cin>>n;
    int m=998244353;
    vector<int> arr(1e6+1,0);
    vector<int> num(1e6,0);
    vector<int> ks(n);
    vector<int> invks(n);
    int ksum=0,a;
    for(int i=0;i<n;i++){
        cin>>ks[i];
        invks[i]=inv((ks[i]*((n*n)%m))%m);
        for(int j=0;j<ks[i];j++){
            cin>>a;
            arr[a]++;
            num[ksum+j]=a;
        }
        ksum+=ks[i];
    }
    int out=0;ksum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<ks[i];j++){
            out+=(arr[num[ksum+j]]*invks[i])%m;
            out%=m;
        }
        ksum+=ks[i];
    }
    cout<<out;
}

int32_t main() {
    FAST
    solve();
}
