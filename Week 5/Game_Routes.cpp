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
    vector<vector<int>> adj(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[b].push_back(a);
    }
    stack<int> q;
    vector<int> dist(n+1,0);
    vector<int> process(n+1,0);
    q.push(n);
    dist[1]=1;
    process[1]=2;
    while(!q.empty()){
        auto p=q.top();
        if(process[p]==1){
            for(auto x:adj[p]){
                    dist[p]+=dist[x];
            };
            dist[p]%=MOD;
            process[p]=2;
            q.pop();
        }
        else if(process[p]==0){
            process[p]=1;
            for(auto x:adj[p]){
                if(process[x]==0)q.push(x);
            };
        }
        else{
            q.pop();
        }
    };
    cout<<dist[n];
}