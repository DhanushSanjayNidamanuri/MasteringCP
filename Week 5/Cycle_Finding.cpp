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
    vector<tuple<int,int,int>> edges(m);
    vector<int> parent(n+1);
    vector<int> dist(n+1,0);
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges[i]=make_tuple(a,b,w);
    }
    int end;
    for(int i=0;i<n;i++){
        end=-1;
        for(auto [a,b,w]:edges){
            if(dist[b]>dist[a]+w){
                dist[b]=dist[a]+w;
                parent[b]=a;
                end=b;
            }
        }
    }
    if(end==-1){
        cout<<"NO";
    }
    else{
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            end = parent[end];

        vector<int> cycle;
        for (int v = end;; v = parent[v]) {
            cycle.push_back(v);
            if (v == end && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}
