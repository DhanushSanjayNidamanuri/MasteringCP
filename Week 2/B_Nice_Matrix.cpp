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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m) );
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int out=0;
    int avg=0;
    vector<int> su(4);
    for(int i=0;i<n/2;i++){
        for(int j=0;j<m/2;j++){
            su[0]=mat[i][j];su[1]=mat[i][m-1-j];su[2]=mat[n-1-i][m-1-j];su[3]=mat[n-1-i][j];
            sort(su.begin(),su.end());
            avg=su[1];
            out+=abs(avg-mat[i][j])+abs(avg-mat[i][m-1-j])+abs(avg-mat[n-1-i][m-1-j])+abs(avg-mat[n-1-i][j]);
        };
    };
    if(n%2!=0){
        for(int j=0;j<m/2;j++){
            out+=abs(mat[n/2][j]-mat[n/2][m-1-j]);
        };
    }
    if(m%2!=0){
            for(int i=0;i<n/2;i++){
            out+=abs(mat[i][m/2]-mat[n-i-1][m/2]);
        };}
    cout<<out<<"\n";
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;

}
