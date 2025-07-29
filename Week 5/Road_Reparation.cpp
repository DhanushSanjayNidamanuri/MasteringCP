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
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(w,b));
        adj[b].push_back(make_pair(w,a));
    }
    priority_queue<pair<int,int>> q;
    vector<bool> visited(n+1,false);
    int out=0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        auto [w,p]=q.top();q.pop();
        if(visited[p])continue;
        visited[p]=true;out+=-w;
        for(auto [w,b]:adj[p]){
            if(visited[b])continue;
            q.push(make_pair(-w,b));
        }
    }
    bool imp=false;
    for(int i=1;i<=n && !imp;i++){
        if(!visited[i])imp=true;
    }
    if(imp)cout<<"IMPOSSIBLE";
    else cout<<out<<"\n";
}
