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
    int a=0,b=0;
    string s;
    cin>>s;
    vector<int> out;
    int p=s.size();
    while(1){
        int i=0,j=s.size()-1;
        int a=0,b=0;
        while(i<j){
            if(a>=b){
                while(s[j]!=')' && i<j)j--;
                s[j]='.';b++;
            }
            else{
                while(s[i]!='(' && i<j)i++;
                s[i]='.';a++;
            }
        }
        if(a==0)
    }

}
