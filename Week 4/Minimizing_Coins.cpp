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

int minimumcoins(int x,vector<int>& coins,vector<int>& calculated){
        if(calculated[x]!=-2)return calculated[x];
        else{
            int minima=1e6;
            bool found=false;
            int k;
            for(auto c:coins){
                if(x-c>0){
                    k=minimumcoins(x-c,coins,calculated);
                    if(k>=0){minima=min(minima,k+1);found=true;}
                }
                else if(x-c==0){
                return 1;
                }
            }
            if(!found){calculated[x]=-1;return calculated[x];}
            calculated[x]=minima;
            return calculated[x];
        }
}

int32_t main() {
    FAST
    int n,x;
    cin>>n;cin>>x;
    vector<int> coins(n,0);
    vector<int> calculated(x+1,-2);
    int maxim=0;
    for(auto& x:coins){
        cin>>x;
        maxim=max(maxim,x);
    }
    if(x%maxim==0)cout<<x/maxim;
    else{cout<<minimumcoins(x,coins,calculated);}
}
