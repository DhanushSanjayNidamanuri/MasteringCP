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
    }
    priority_queue<pair<int,int>> q;
    vector<int> dist(n+1,-1);
    for(auto x:adj[1]){
        q.push(make_pair(-x.first,x.second));
    }
    dist[1]=0;
    while(!q.empty()){
        auto x=q.top();q.pop();
        if(dist[x.second]>=0)continue;
        dist[x.second]=(-x.first);
        for(auto ad:adj[x.second]){
            if(dist[ad.second]<0){
                q.push(make_pair(-ad.first+x.first,ad.second));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}
