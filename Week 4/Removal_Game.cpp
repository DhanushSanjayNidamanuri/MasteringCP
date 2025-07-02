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
int score(bool play1,int i,int j,vector<int>& arr,int& sum,vector<vector<int>>& memo,vector<vector<bool>>& boolmemo){
    if(i>j)return 0;
    if(boolmemo[i][j])return memo[i][j];
    if(play1){
        int c1=score(false,i+1,j,arr,sum,memo,boolmemo),c2=score(false,i,j-1,arr,sum,memo,boolmemo);
        if(arr[i]+c1>arr[j]+c2){boolmemo[i][j]=true;memo[i][j]=arr[i]+c1;return arr[i]+c1;}
        else{boolmemo[i][j]=true;memo[i][j]=arr[j]+c2;return arr[j]+c2;}
    }
    int c1=score(true,i+1,j,arr,sum,memo,boolmemo),c2=score(true,i,j-1,arr,sum,memo,boolmemo);
    if(sum-c1>sum-c2)return c1;
    else return c2;
}

void solve() {
    // your logic here


    int n;
    cin>>n;
    vector<int> arr(n);
    vector<vector<int>> memo(n,vector<int>(n));
    vector<vector<bool>> boolmemo(n,vector<bool>(n,false));
    int sum=0;
    for(int i=0;i<n;i++){cin>>arr[i];sum+=arr[i];}
    cout<<score(true,0,n-1,arr,sum,memo,boolmemo);
}

int32_t main() {
    FAST
    int t = 1;
    while (t--) solve();
    return 0;
}
