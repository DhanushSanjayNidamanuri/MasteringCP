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
const int INF=-1e18;
using vi = vector<int>;
using pii = pair<int, int>;
 
void cycl(int i,vector<int>& cycle,vector<vector<pair<int,int>>>& adj){
    if(cycle[i])return;
    else{
        cycle[i]=1;
        for(auto x:adj[i]){
            cycl(x.first,cycle,adj);
        }
    }
}
 
void dfs(int i,int dis,vector<vector<pair<int,int>>>& adj,vector<int>& state,vector<int>& dist,vector<int>& cycle){
    if(state[i]==1 && dis>dist[i]){dist[i]=max(dist[i],dis);cycl(i,cycle,adj);}
    else if(state[i]==1)return;
    else{
        bool out =true;
        dist[i]=max(dis,dist[i]);
        state[i]=1;
        for(auto x:adj[i]){
            dfs(x.first,dist[i]+x.second,adj,state,dist,cycle);
        }
        state[i]=2;
        return ;
    }
}
 
int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
    }
    vector<int> state(n+1,0);
    vector<int> dist(n+1,INF);
    vector<int> cycle(n+1,0);
    dist[1]=0;
    dfs(1,0,adj,state,dist,cycle);
    if(!cycle[n])cout<<dist[n];
    else cout<<"-1";
}