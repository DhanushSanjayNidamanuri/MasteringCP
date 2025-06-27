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
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++){cin>>arr[i];};
    int k=n;
    sort(arr.begin(),arr.end());
    for(;k>=1;k/=4){
        for(int i=n-k;i<n;i++)
        {sum+=arr[i];}
    }

    cout<<sum;
    return 0;
}
