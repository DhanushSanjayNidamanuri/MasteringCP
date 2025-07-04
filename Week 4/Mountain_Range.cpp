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

int ways(int i,vector<int>& memo,const int& n,const vector<int>& mounts){
    if(memo[i])return memo[i];
    int lmax=0,rmax=0,out=1,present=mounts[i];
    for(int j=i+1;j<n && mounts[j]<present;j++)rmax=max(rmax,mounts[j]);
    for(int j=i+1;j<n && mounts[j]<present;j++)if(mounts[j]==rmax){out=max(out,1+ways(j,memo,n,mounts));}
    for(int j=i-1;j>=0 && mounts[j]<present;j--)lmax=max(lmax,mounts[j]);
    for(int j=i-1;j>=0 && mounts[j]<present;j--)if(mounts[j]==lmax){out=max(out,1+ways(j,memo,n,mounts));}
    memo[i]=out;
    return out;
}


void solve() {
    int n;
    cin>>n;
    vector<int> mounts(n);vector<int> memo(n,0);
    int maximum=0;
    for(int i=0;i<n;i++){cin>>mounts[i];if(mounts[i]>maximum){maximum=mounts[i];}}
    if(n>=2){
        if(mounts[0]<=mounts[1])memo[0]=1;
        if(mounts[n-1]<=mounts[n-2])memo[n-1]=1;
        for(int i=1;i<n-1;i++){
            if(mounts[i-1]>=mounts[i] && mounts[i+1]>=mounts[i])memo[i]=1;
        }
    }
    int out=0;
    for(int i=0;i<n;i++)if(mounts[i]==maximum)out=max(out,ways(i,memo,n,mounts));
    cout<<out;
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
