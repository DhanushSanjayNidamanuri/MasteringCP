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
vector<bool> isprime(1e6+1,true);
vector<int> actualprime(1e6+1,0);
void solve() {
    // your logic here
    int out=1,n;
    cin>>n;
    int k;
    if(isprime[n])cout<<2<<"\n";
    else {
        for(int i=0;n>1;i++){
        k=0;
        if(isprime[n]){out*=2;break;}
        while(n%actualprime[i]==0){
            n/=actualprime[i];
            k++;
        }
        out*=k+1;
        }
        cout<<out<<"\n";
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    isprime[1]=false;
    for(int i=2,j=0;i<isprime.size();i++){
        if(isprime[i]){
            for(int j=2*i;j<isprime.size();j+=i){
                isprime[j]=false;
            }
            actualprime[j]=i;j++;
        }
    }
    while (t--) solve();
    return 0;
}
