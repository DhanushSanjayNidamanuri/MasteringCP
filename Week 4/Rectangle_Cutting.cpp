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
 
int ans(int a,int b,vector<vector<int>>& memo){
    if(memo[a][b]>=0)return memo[a][b];
    if(a==b){memo[a][b]=0 ;return 0;}
    int mini=max(a,b);
    for(int i=1;i<=a/2;i++){
        mini=min(mini,1+ans(a-i,b,memo)+ans(i,b,memo));
    }
    for(int i=1;i<=b/2;i++){
        mini=min(mini,1+ans(a,b-i,memo)+ans(a,i,memo));
    }
    memo[a][b]=mini;
    return memo[a][b];
}
 
void solve() {
    // your logic here
    int a,b;
    cin>>a>>b;
    vector<vector<int>> memo(a+1,vector<int> (b+1,-1));
    cout<<ans(a,b,memo);
}
 
int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}