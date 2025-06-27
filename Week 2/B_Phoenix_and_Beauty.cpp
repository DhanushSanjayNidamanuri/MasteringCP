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
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> num;
    bool found=false;
    for(auto x:arr){
        for(auto y:num){
            found =false;
            if(y==x){found=true;break;}
        }
        if(!found)num.push_back(x);
    }
    if(k<num.size()){cout<<"-1\n";}
    else{
        for(int i=1;i<=n && num.size()<k;i++){
                num.push_back(i);
        }
        cout<<(k*(arr.size()))<<"\n";
        for(int i=0;i<n-1;i++){
            for(auto x:num){
                cout<<x<<" ";
            }
        }
        for(int i=0;i<num.size()-1;i++){
            cout<<num[i]<<" ";
        }
        cout<<*(num.end()-1)<<"\n";
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
