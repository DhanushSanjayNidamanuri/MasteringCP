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

void solve() {
    // your logic here
    int x,y,k=0;
    cin>>x>>y;
    int i=0,j=-1;
    int mask=1;
    bool cant=false;
    while(i<64){
        if(bool(x&mask) ^ bool(y&mask)){j=i;}
        else if((x&mask)==0 && (y&mask)==0){   
        }
        else{
            if(j!=-1){
            while(i!=j){
                x+=(1ULL<<j);y+=(1ULL<<j);k+=(1ULL<<j);j++;
            };}
            else{
                x+=(1ULL<<i);y+=(1ULL<<i);k+=(1ULL<<i);
                if(i==63)cant=true;
            }
        }
        i++;mask*=2ULL;
    }
    if(cant)cout<<"-1\n";
    else cout<<k<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
