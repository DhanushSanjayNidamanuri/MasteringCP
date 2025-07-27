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
    // your logic here
}

int32_t main() {
    FAST
    int n;
    cin>>n;
    int port[n+1];
    rep(i,1,n+1)cin>>port[i];
    int out[n+1];
    int vis[n+1];
    rep(i,1,n+1)out[i]=0;
    rep(i,1,n+1)vis[i]=0;
    bool cyc[n+1];
    rep(i,1,n+1)cyc[i]=false;
    int p,a,p2;
    for(int i=1;i<=n;i++){
        if(out[i]!=0)continue;
        p=i;a=0;
        while(1){
            if(vis[p]==i)break;
            if(out[p]!=0)break;
            vis[p]=i;p=port[p];a++;
        }
        if(out[p]==0){
            p2=i;
            while(p2!=p){
                out[p2]=a;
                a--;
                p2=port[p2];
            }
            out[p]=a;
            p2=port[p2];
            cyc[p]=true;
            while(p2!=p){
                out[p2]=a;
                p2=port[p2];
            }
        }
        else{
            p2=i;
            a+=out[p];
            while(p2!=p){
                out[p2]=a;
                a--;
                p2=port[p2];
            }
        }    
    }
    for(int i=1;i<=n;i++){cout<<out[i]<<" ";}
}
