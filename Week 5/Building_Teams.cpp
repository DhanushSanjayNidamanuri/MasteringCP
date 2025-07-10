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

bool paint(int i,bool team,vector<bool>& set,vector<bool>& color,vector<vector<int>>& adj){
    set[i]=true;color[i]=team;
    bool out=true;
    for(auto x:adj[i]){
        if(set[x] && color[x]==team)return false;
        else if(set[x])continue;
        else if(!set[x])out=paint(x,!team,set,color,adj);
        if(!out)return false;
    }
    return out;
}

int32_t main() {
    FAST

    int n,m;
    cin>>n>>m;
    vector<bool> color(n+1,false);
    vector<bool> set(n+1,false);
    vector<vector<int>> adj(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ok=true;
    int i=1;
    while(i<=n && ok){
        for(;i<=n;i++){           
            if(!set[i]){;ok=paint(i,true,set,color,adj);i++;break;}
        }
    }
    if(!ok)cout<<"IMPOSSIBLE";
    else{
        for(int i=1;i<=n;i++){
            if(color[i])cout<<"1 ";
            else cout<<"2 ";
        }
    }
}
