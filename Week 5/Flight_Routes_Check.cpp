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
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    vector<int> process(n+1,0);
    stack<int> q;
    int p;
    vector<int> l;
    for(int i=1;i<=n;i++){
        if(process[i]==2){continue;}
        q.push(i);
        while(!q.empty()){
            p=q.top();
            if(process[p]==0){
                process[p]=1;
                for(auto b:adj[p]){
                    if(process[b]==0)q.push(b);
                }
            }
            else if(process[p]==1){
                process[p]=2;l.push_back(p);q.pop();
            }
            else{
                q.pop();
            }
        }
    }
    reverse(l.begin(),l.end());
    int comps=0;
    vector<int> out;
    rep(i,1,n+1)process[i]=0;
    int i;
    for(int j=0;j<n;j++){
        i=l[j];
        if(process[i]==2)continue;
        q.push(i);
        comps++;
        out.push_back(i);
        if(comps==2)break;
        while(!q.empty()){
            p=q.top();
            if(process[p]==0){
                process[p]=1;
                for(auto b:rev[p]){
                    if(process[b]==0)q.push(b);
                }
            }
            else if(process[p]==1){
                process[p]=2;l.push_back(p);q.pop();
            }
            else{
                q.pop();
            }
        }
    }
    if(comps>=2){
        cout<<"NO\n"<<out[1]<<" "<<out[0];
    }
    else{
        cout<<"YES\n";
    }
}
