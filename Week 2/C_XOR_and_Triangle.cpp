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

void solve() {
    // your logic here
    int x,y;
    cin>>x;
    y=0;
    if(__builtin_popcount(x)<=1)cout<<"-1\n";
    else{
        bool task1=false,task2=false,task3=false;
        for(int i=0;i<64;i++){
            if(!task1 && ((x>>i) & 1)==1) {
                task1=true;y+=(1<<i);
            }
            else if(!task2 || !task3){
                if((x>>i) & 1 ==1){
                    task2=true;
                }
                else{
                    y=y+(1<<i);task3=true;
                }
            }
            else{
                break;
            }
        }
        if(y<x)cout<<y<<"\n";
        else cout<<"-1\n";
    }
}
int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
