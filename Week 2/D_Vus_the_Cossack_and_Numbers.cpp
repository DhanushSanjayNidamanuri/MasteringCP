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
    int n = 1;
    cin >> n;
    vector<pair<int,bool>> arr(n);
    float t;
    int k,sum=0;
    for(auto &x:arr){
        cin>>t;
        k=floor(t);
        x.second=(t!=k);
        x.first=k;
        sum+=k;
    }
    for(int i=0;i<n && sum<0;i++){
        if(arr[i].second){arr[i].first++;sum++;}
    }
    for(auto x:arr){
        cout<<x.first<<"\n";
    }
}
