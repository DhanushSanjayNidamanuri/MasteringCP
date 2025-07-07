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

void close(int i,int j,vector<vector<bool>>& expandable){
    expandable[i][j]=false;
    if(expandable[i+1][j])close(i+1,j,expandable);
    if(expandable[i][j+1])close(i,j+1,expandable);
    if(expandable[i-1][j])close(i-1,j,expandable);
    if(expandable[i][j-1])close(i,j-1,expandable);

    
    return;
}


int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> expandable(n+2,vector<bool>(m+2,false));
    char inp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>inp;
            if(inp=='.')expandable[i][j]=true;
        }
    }
    int rooms=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(expandable[i][j]){
                rooms++;
                close(i,j,expandable);
            }
        }
    }
    cout<<rooms;
}
