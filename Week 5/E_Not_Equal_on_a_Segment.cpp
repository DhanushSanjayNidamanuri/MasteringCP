#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);

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
    int n,t;
    cin>>n>>t;
    unordered_map<int,vector<int>> pos;
    int x;
    for(int i=1;i<=n;i++){cin>>x;pos[x].push_back(i);}
    int l,r;bool found;
    while(t--){
        cin>>l>>r>>x;found=false;
        for(auto p:pos[x]){
            if(p>=l && p<=r){cout<<p<<"\n";found=true;break;}
        }
        if(!found)cout<<"-1\n";
    }
}
