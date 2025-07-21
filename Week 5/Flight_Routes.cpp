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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<int>> back(n+1);
    vector<bool> reachable(n+1,false);
    vector<vector<int>> dist(n+1);
    vector<int> distn;
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(w,b));
        back[b].push_back(a);
    }

    queue<int> rs;
    rs.push(n);
    while(!rs.empty()){
        int a=rs.front();rs.pop();
        if(reachable[a])continue;
        else{
            reachable[a]=true;
            for(auto x:back[a]){
                rs.push(x);
            }
        }
    }


    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,1));
    while(distn.size()<k){
        auto [pd,a]=q.top();q.pop();
        if(!reachable[a] || dist[a].size()>=k)continue;
        dist[a].push_back(-pd);
        if(a==n)distn.push_back(-pd);
        for(auto [w,b]:adj[a]){
            q.push(make_pair(pd-w,b));
        }
    }
    for(auto x:distn){
        cout<<x<<" ";
    }
}
