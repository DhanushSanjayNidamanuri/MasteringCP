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


int32_t main() {
    FAST
    int n,q;
    cin>>n>>q;
    int port[n+1];
    rep(i,1,n+1)cin>>port[i];
    int a,b;
    while(q--){
        vector<bool> vis(n+1,false);
        cin>>a>>b;
        int l=0;
        while(a!=b){
            if(vis[a]){cout<<"-1\n";break;}
            vis[a]=true;
            a=port[a];
            l++;
        }
        if(a==b)cout<<l<<"\n";
    }
}
