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
    if(n==0){cout<<"1";}
    else{
        n%=4;
    if(n==1)cout<<"8";
    else if(n==2)cout<<"4" ;  
    else if(n==3)cout<<"2";
    else if(n==0)cout<<"6";}

}

int32_t main() {
    FAST
solve();
    return 0;
}
