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

int calculate(int x,int p,int i,vector<int>& coins){
    if(p==x)return 1;
    else{
        int out=0;
        int s=coins.size();
        for(int k=i;k<s;k++)
            if(p+coins[k]<=x)out+=calculate(x,p+coins[k],k,coins);
        return out;
    }
}

int32_t main() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    sort(coins.begin(),coins.end());
    cout<<calculate(x,0,0,coins);
}

