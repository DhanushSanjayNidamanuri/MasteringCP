#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define int unsigned long long

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


int MOD=1e9+7;

int power(int a,int b){
    int out=1;
    while(b>0){
        if(b & 1){
            out*=a;
            out%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return out;
}
int inv(int x) {if(x==1) return 1; else return power(x, MOD - 2); }
void solve() {
    // your logic here
    ifstream file("sumdiv.in") ;
    ofstream outfile("sumdiv.out");
    int a,b;
    file>>a>>b;
    int k=a;
    if(b==0)a=1;
    map<int,int> factorz;
    for(int i=2;a>1 && i*i<=k ;i++){
        while(a%i==0){
            a/=i;factorz[i]++;
        }
    }
    if(a!=1)factorz[a]++;
    int out=1,p;
    for(auto x:factorz){
         if((x.first-1)%MOD!=0){p=(power(x.first,(((x.second)%(MOD-1))*((b)%(MOD-1))+1)%(MOD-1))-1+MOD)%MOD;
         p*=inv((x.first-1)%MOD);
         p%=MOD;}
         else{
            p=(x.second*b + 1)%MOD;
         }
        out*=p;
        out%=MOD;
    }
    outfile<<out;
}
int32_t main() {
    FAST
     solve();

}
