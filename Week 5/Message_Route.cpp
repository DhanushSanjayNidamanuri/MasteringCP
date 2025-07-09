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
    vector<int> adj[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    queue<int> q;
    q.push(1);
    int present;bool found=false;
    while(!q.empty() && !found){
        present=q.front();
        q.pop();
        for(auto x:adj[present]){
            if(parent[x]==x){
                q.push(x);parent[x]=present;
                if(x==n)found=true;
            }
        }
    }
    if(parent[n]==n)cout<<"IMPOSSIBLE";
    else{
        vector<int> backtrace;
        int x=n;
        while(x!=1){
            backtrace.push_back(x);
            x=parent[x];
        }
        cout<<backtrace.size()+1;
        cout<<"\n"<<"1 ";
        for(int i=backtrace.size()-1;i>=0;i--){
            cout<<backtrace[i]<<" ";
        }
    }
    return 0;
}
