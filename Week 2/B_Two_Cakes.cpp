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
    int n;
    cin>>n;
    n*=2;
    vector<int> a(n/2+1),b(n/2+1);
    for(int i=0;i<n/2+1;i++){
        a[i]=b[i]=0;
    }
    int k,p1,p2;
    for(int i=1;i<n+1;i++){
        cin>>k;
        if(a[k]==0)a[k]=i;
        else b[k]=i;
    }
    p1=p2=1;
    k=0;
    int t=0;
    for(int i=1;i<=n/2;i++){
        t=min((max(p1,a[i])-min(p1,a[i])+max(p2,b[i])-min(p2,b[i])),(max(p2,a[i])-min(p2,a[i])+max(p1,b[i])-min(p1,b[i])));
        if(t==(max(p1,a[i])-min(p1,a[i])+max(p2,b[i])-min(p2,b[i]))){p1=a[i];p2=b[i];}
        else{p1=b[i];p2=a[i];};
        k+=t;
    }
    cout<<k;
}

int32_t main() {
    FAST
    solve();
    return 0;
}
