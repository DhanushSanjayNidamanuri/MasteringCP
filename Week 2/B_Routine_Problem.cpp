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
    int m,n,p,q;
    cin>>m>>n>>p>>q;
    int a,b;
    if(m*q==n*p)cout<<"0/1";
    else{
        if(m*q>n*p){
        a=m*q-n*p;b=m*q;
        }
        else{
            a=n*p-q*m;b=n*p;
        }
        for(int i=2;i<=min(a,b);i++){
            while(a%i==0 && b%i==0)
            {a/=i;b/=i;}
        }
        cout<<a<<"/"<<b;
    }
}

