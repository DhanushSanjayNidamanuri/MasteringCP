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
    int m=(1e9)+7;
    int a,b,c;
    cin>>a>>b>>c;
    int out1=1,out2=1;
    while(c>0){
        if(c & 1){
            out1*=b;
            out1%=(m-1);
        }
        b=(b*b)%(m-1);
        c=c>>1;
    }
    if(a==1 || (a==0 && out1==0)){
        cout<<"1\n";
    }
    else{
        while(out1>0){
            if(out1 & 1){
                out2*=a;
                out2%=m;
            }
            a=(a*a)%m;
            out1=out1>>1;
        }
        cout<<out2<<"\n";
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
