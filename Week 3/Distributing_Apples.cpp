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
int MOD=1e9+7;
int power(int a,int b){
    int out=1;
    while(b>0){
        if(b & 1){
            out*=a;
            out%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return out;
}
vector<int> arr(1e6*2+1,0);
int inv(int x) {if(x==1) return 1; else return power(x, MOD - 2); }
int factorial(int n){
    if(arr[n]!=0) return arr[n];
    else {arr[n]=(n*factorial(n-1))%MOD;
        return arr[n];}
}

void solve() {
    // your logic here
    int n,m,a,b;
    cin>>n>>m;
    a=m+n-1;
    b=m;
    int out=1,deno=1;
    out*=factorial(a);
    deno=(factorial(b)*factorial(a-b))%MOD;
    cout<<(out*inv(deno))%MOD<<"\n";

}

int32_t main() {
    FAST
    int t = 1;
    arr[0]=1;
    arr[1]=1;
    while (t--) solve();
    return 0;
}