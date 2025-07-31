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
    cin>>m>>n;
    vector<vector<int>> adj(2*n+1);
    vector<vector<int>> rev(2*n+1);
    int a,b;
    char s1,s2;
    for(int i=0;i<m;i++){
        cin>>s1>>a>>s2>>b;
        if(s1=='-')a+=n;
        if(s2=='-')b+=n;
        if(a!=n){
            adj[(a+n)%(2*n)].push_back(b);
            rev[b].push_back((a+n)%(2*n));
        }
        else{
            adj[2*n].push_back(b);
            rev[b].push_back(2*n);
        }
        if(b!=n){
            adj[(b+n)%(2*n)].push_back(a);
            rev[a].push_back((b+n)%(2*n));
        }
        else{
            adj[2*n].push_back(a);
            rev[a].push_back(2*n);
        }
    }
    vector<int> process(2*n+1,0);
    stack<int> q;
    int p;
    vector<int> l;
    for(int i=1;i<=2*n;i++){
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
    vector<int> out(2*n+1);
    rep(i,1,2*n+1)process[i]=0;
    int i;
    for(int j=0;j<2*n;j++){
        i=l[j];
        if(process[i]==2)continue;
        q.push(i);
        comps++;
        while(!q.empty()){
            p=q.top();
            if(process[p]==0){
                process[p]=1;
                for(auto b:rev[p]){
                    if(process[b]==0)q.push(b);
                }
            }
            else if(process[p]==1){
                process[p]=2;l.push_back(p);q.pop();out[p]=comps;
            }
            else{
                q.pop();
            }
        }
    }
    bool found=false;
    for(int i=1,j=n+1;i<=n;i++,j++){
        if(out[i]==out[j]){found =true;cout<<"IMPOSSIBLE";break;}
    }
    if(!found){
        reverse(l.begin(),l.end());
        vector<char> signs(n+1,'.');
        for(auto x:l){
            if(x!=n && x!=2*n){
                if(signs[x%n]!='.')continue;
                if(x>n)signs[x%n]='-';
                else signs[x]='+';
            }
            else{
                if(signs[n]!='.')continue;
                if(x>n)signs[n]='-';
                else signs[n]='+';
            }
        }
        for(int i=1;i<=n;i++){
            cout<<signs[i]<<" ";
        }
    }
}
