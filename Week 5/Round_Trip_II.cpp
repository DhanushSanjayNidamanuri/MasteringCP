#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);

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

void backtrace(int b,vector<int>& parent){
    vector<int> out;
    out.push_back(b);
    int x=parent[b];
    while(x!=b){
        out.push_back(x);
        x=parent[x];
    }
    out.push_back(b);
    cout<<out.size()<<"\n";
    for(int i=out.size()-1;i>=0;i--)cout<<out[i]<<" ";
}

int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> process(n+1,0);
    stack<int> q;
    vector<int> parent(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    bool found=false;
    for(int i=1;i<=n && !found;i++){
        if(process[i])continue;
        parent[i]=i;
        q.push(i);
        while(!q.empty() && !found){
            auto a=q.top();
            if(process[a]==1){
                process[a]=2;q.pop();
            }
            else if(process[a]==0){
                process[a]=1;
                for(auto b:adj[a]){
                    if(process[b]==1){
                        parent[b]=a;found=true;backtrace(b,parent);break;
                    }
                    else if(process[b]==0){
                        parent[b]=a;
                        q.push(b);
                    }
                };
            }
            else if(process[a]==2)q.pop();    
        }
    }
    if(!found)cout<<"IMPOSSIBLE\n";
}
