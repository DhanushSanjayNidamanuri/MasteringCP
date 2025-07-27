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

int32_t main() {
    FAST
    int n;
    int t = 1;
    cin >>n>> t;
    int port[n+1][31];
    for(int i=1;i<=n;i++){
        cin>>port[i][0];
    }
    for(int j=1;j<=30;j++){
        for(int i=1;i<=n;i++){
            port[i][j]=port[port[i][j-1]][j-1];
        }
    }
    int a,k,j;
    while (t--) {
        cin>>a>>k;
        j=0;
        while(k>0){
            if(k&1)a=port[a][j];
            k=k>>1;j++;
        }
        cout<<a<<"\n";
    }
}
