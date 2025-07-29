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

int find(int a,vector<int>& comp){
    while(a!=comp[a])a=comp[a];
    return a;
}

void uni(int a,int b,vector<int>& size,vector<int>& comp,int& out,int& no){
    a=find(a,comp);b=find(b,comp);
    if(a!=b){
        if(size[a]<size[b])swap(a,b);
        comp[b]=a;
        size[a]+=size[b];
        out=max(out,size[a]);
        no--;
    };
}

int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<int> size(n+1,1);
    vector<int> comp(n+1);
    rep(i,1,n+1)comp[i]=i;
    int a,b,out=0,no=n;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        uni(a,b,size,comp,out,no);
        cout<<no<<" "<<out<<"\n";
    }
}
