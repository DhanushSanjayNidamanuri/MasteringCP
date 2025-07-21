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

int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<int>> back(n+1);
    vector<int> dist(n+1);
    vector<int> visited(n+1,false);
    int a,b,w;
    rep(i,0,m){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(w,b));
    }
    priority_queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,1,1));
    while(!q.empty()){
        auto [pd,p,parent]=q.top();q.pop();
        if(visited[p] && dist[p]==-pd){back[p].push_back(parent);continue;}
        else if(visited[p])continue;
        dist[p]=-pd;
        back[p].push_back(parent);
        for(auto [xd,x]:adj[p]){
            q.push(make_tuple(pd-xd,x,p));
        }
        visited[p]=true;
    }
    cout<<dist[n]<<" ";
    vector<int> paths(n+1,0);
    vector<int> maxs(n+1,0);
    vector<int> mins(n+1,dist[n]);
    vector<int> process(n+1,0);
    paths[1]=1;maxs[1]=0;mins[1]=0;process[1]=2;
    stack<int> stk;
    stk.push(n);

    while(!stk.empty()){
        auto p=stk.top();
        if(process[p]==0){
            process[p]=1;
            for(auto x:back[p]){
                if(process[x]==0)stk.push(x);
            }
        }
        else if(process[p]==1){
            process[p]=2;stk.pop();
            for(auto x:back[p]){
                paths[p]+=paths[x];
                paths[p]%=MOD;
                maxs[p]=max(maxs[p],maxs[x]+1);
                mins[p]=min(mins[p],mins[x]+1);
            }
        }
        else{
            stk.pop();
        }
    }
    cout<<paths[n]<<" "<<mins[n]<<" "<<maxs[n];
}
