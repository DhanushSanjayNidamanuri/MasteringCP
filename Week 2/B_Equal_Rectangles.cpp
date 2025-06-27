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

int solve() {
    // your logic here
    int n;
        cin>>n;
    vector<int> len(4*n);
    for(int i=0;i<4*n;i++){
        cin>>len[i];
    }
    sort(len.begin(),len.end());
    bool one=true;
    for(int i=0;i<4*n;i+=2){
        if(len[i]!=len[i+1])one=false;
    }
    if(!one)return 0;
    int area=len[0]*len[(4*n)-1];
    for(int i=0;i<2*n;i+=2){
        if(area!=len[i]*len[(4*n)-1-i])one=false;}
    if(!one)return 0;
    else return 1;
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) {
        int k=solve();
        if(k==1){cout<<"YES\n";}
        else{cout<<"NO\n";};
    };
    return 0;
}
