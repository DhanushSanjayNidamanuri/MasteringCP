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

void solve() {
    // your logic here
    int n;
    cin>>n;
    if(n==4)cout<<"2 4 1 3";
    else if(n==1)cout<<"1";
    else if(n==2 || n==3)cout<<"NO SOLUTION";
    else{
        int i=1,j;
        if(n%2==0)j=n/2 +1;
        else j=n/2+2;
        for(;i<=n/2 && j<=n-1;i++,j++){
            cout<<i<<" "<<j<<" ";
        }
        if(n%2==0)cout<<n/2<<" "<<n;
        else cout<<n/2<<" "<<n<<" "<<n/2+1;
    }
}

int32_t main() {
    FAST
     solve();
    return 0;
}


