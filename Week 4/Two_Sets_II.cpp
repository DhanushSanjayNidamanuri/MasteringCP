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
const int MOD=1e9+7;
int ways(int& n,int i,int sum1,vector<vector<int>> & memo,int& k){
    if(memo[i][sum1]>=0)return memo[i][sum1];
    if(i>n){
        if(sum1==k){memo[i][sum1]=1;return 1;}
        else {memo[i][sum1]=0;return 0;}
    }
    memo[i][sum1]=0;
    if(sum1+i<=k)memo[i][sum1]+=ways(n,i+1,sum1+i,memo,k);
    memo[i][sum1]+=ways(n,i+1,sum1,memo,k);
    return memo[i][sum1]%MOD;
}

void solve() {
    // your logic here
    int n;
    cin>>n;
    if(n%4!=0 && (n+1)%4!=0)cout<<0;
    else{
        int k=(n*(n+1))/4;
        vector<vector<int>> memo(n+2,vector<int>(((n*(n+1))/2)+1,-1));
        cout<<(ways(n,1,0,memo,k)*500000004)%MOD;
    }
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
