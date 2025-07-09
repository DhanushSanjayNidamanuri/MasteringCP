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

int find(int i,vector<int>& arr,int& length){
    while(i!=arr[i]){
        i=arr[i];length++;
    }
    return i;
}

void connect(int a,int b,vector<int>& arr){
    int l1=0,l2=0;
    int r1=find(a,arr,l1),r2=find(b,arr,l2);
    if(r1==r2)return;
    if(l1<l2)arr[r1]=r2;
    else arr[r2]=r1;
    return;
}

int32_t main() {
    FAST
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)arr[i]=i;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        connect(a,b,arr);
    }
    int out=0;
    int i=1;
    int initial,final;
    for(;i<=n;i++)if(i==arr[i]){out++;initial=i;break;};
    i++;
    for(;i<=n;i++)if(i==arr[i]){out++;};
    cout<<out-1<<"\n";
    int k=out-1,previous=initial,present;
    for(int t=initial+1;t<=n && k;t++){
        if(arr[t]==t){cout<<previous<<" "<<t<<"\n";previous=t;k--;}
    }
}
