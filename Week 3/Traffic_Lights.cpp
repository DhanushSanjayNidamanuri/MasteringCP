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
    int n,x;
    cin>>n>>x;
    n+=1;
    vector<bool> lights(n,false);
    int maxi=0,j,p,q;
    for(int i=0;i<x;i++){
        cin>>j;
        lights[j]=true;
        for(p=0,q=0,maxi=0;q<n && maxi<=n/2;q++){
            if(lights[q]){maxi=max(q-p,maxi);p=q;}
        }
        if(q==n)maxi=max(q-p-1,maxi);
        cout<<maxi<<" ";
    }
}

int32_t main() {
    FAST
    solve();
    return 0;
}


