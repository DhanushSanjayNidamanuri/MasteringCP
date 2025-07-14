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
const int MOD=1e9+7;
void solve() {
    // your logic here
    string s;
    cin>>s;
    int as[s.size()+1];
    int bs[s.size()+1];
    as[0]=0;bs[0]=0;
    for(int i=1;i<=s.size();i++){
        if(s[i-1]=='0'){as[i]=as[i-1]+1;bs[i]=bs[i-1];}
        else {bs[i]=bs[i-1]+1;as[i]=as[i-1];}
    }
    int out=0;
    for(int i=1;i<=s.size();i++){
        for(int j=i+1;j<=s.size();j++){
            if(as[j]-as[i-1]==bs[j]-bs[i-1]){out+=(i)*(s.size()-j+1);out%=MOD;}
        }
    }
    cout<<out<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
