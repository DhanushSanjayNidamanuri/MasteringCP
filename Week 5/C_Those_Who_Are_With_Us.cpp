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
    int n,m,a,glomax=0,count=0;
    cin>>n>>m;
    vector<int> rowmax(n,0),colmax(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            if(a>rowmax[i])rowmax[i]=a;
            if(a>colmax[j])colmax[j]=a;
            if(a>glomax){glomax=a;count=0;}
            if(a==glomax)count++;
        }
    }
    int p=0,q=0;
    for(auto x:rowmax)if(x==glomax)p++;
    for(auto x:colmax)if(x==glomax)q++;
    if(count<=2)cout<<glomax-1<<"\n";
    else if(p>=3 && q>=3)cout<<glomax<<"\n";
    else if((p==3 || q==3)&& count<=3)cout<<glomax-1<<"\n";
    else if((p==3 || q==3)&& count>=5)cout<<glomax<<"\n";
    else cout<<glomax-1<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
