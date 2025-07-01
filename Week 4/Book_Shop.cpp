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
int maxpages(int i,int& n,int pagescount,int price,int& x,vector<int>& prices,vector<int>& pages){
    for(;i<n;i++){
        if(price+prices[i]<=x)break;
    }
    if(i==n)return pagescount;
    int out=0;
    out=max(maxpages(i+1,n,pagescount+pages[i],price+prices[i],x,prices,pages),maxpages(i+1,n,pagescount,price,x,prices,pages));
    return out;
}
void solve() {
    // your logic here
    int n,x;
    cin>>n>>x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++)cin>>prices[i];
    for(int i=0;i<n;i++)cin>>pages[i];
    cout<<maxpages(0,n,0,0,x,prices,pages);
}
\


int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
