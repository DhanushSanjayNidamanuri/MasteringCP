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
int ways(int i,int j,int& n,vector<vector<int>>& counts,vector<vector<bool>>& states){
    if(i==n && j==n)return 1;
    int out=0,k1,k2;
    if(j<n && states[i][j+1]){
        if(counts[i][j+1]==-1)counts[i][j+1]=ways(i,j+1,n,counts,states)%MOD;
        out+=counts[i][j+1];
        }
    if(i<n && states[i+1][j]){
        if(counts[i+1][j]==-1)counts[i+1][j]=ways(i+1,j,n,counts,states)%MOD;
        out+=counts[i+1][j];
        }
    out%=MOD;
    return out;
}
void solve() {
    // your logic here
    int n;
    cin>>n;
    vector<vector<int>> counts(n,vector<int>(n,-1));
    vector<vector<bool>> states(n,vector<bool>(n,true));
    char state;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>state;
            if(state=='*')states[i][j]=false;
        }
    }
    n--;
    if(!states[0][0])cout<<0;
    else cout<<ways(0,0,n,counts,states);
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
