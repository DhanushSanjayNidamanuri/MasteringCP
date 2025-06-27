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
int MOD=1e9+7;
int die(int k,vector<int>& memo){
    if(memo[k])return memo[k];
    else{
        memo[k]+=die(k-1,memo)+die(k-2,memo)+die(k-3,memo)+die(k-4,memo)+die(k-5,memo)+die(k-6,memo);
        memo[k]%=MOD;
        return memo[k];
    }
}
int32_t main() {
    FAST
    int n;
    cin>>n;
    vector<int> memo(n+1,0);
    memo[1]=1;
    memo[2]=2;
    memo[3]=4;    
    memo[4]=8;
    memo[5]=16;
    memo[6]=32;
    cout<<die(n,memo);
}
