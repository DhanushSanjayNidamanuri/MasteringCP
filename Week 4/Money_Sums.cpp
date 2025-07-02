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

void solve() {

    // your logic here
    int n;
    cin>>n;
    vector<int> coins(n);
    int sum=0;
    for(int i=0;i<n;i++){cin>>coins[i];sum+=coins[i];}
    vector<int> possible(sum+1,-1);
    int present;
    int presentsum=0;
    possible[sum]=0;
    for(int i=0;i<n;i++){
        present=coins[i];
        presentsum+=present;
        if(possible[present]<0)possible[present]=i;
        for(int j=1;j<=presentsum;j++){
            if(possible[j]>=0 && possible[j]!=i && possible[j+present]<0)possible[j+present]=i;
        }
    }
    int out=0;
    for(int i=1;i<=sum;i++){
        if(possible[i]>=0)out++;
    }
    cout<<out<<endl;
    for(int i=1;i<=sum;i++){
        if(possible[i]>=0)cout<<i<<" ";
    }
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
