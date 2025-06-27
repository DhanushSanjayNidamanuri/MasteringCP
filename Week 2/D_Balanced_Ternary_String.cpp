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
}

int32_t main() {
    string s;
    int n;
    cin>>n;
    cin>>s;
    int ziros=0,ones=0,twos=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')ziros++;
        else if(s[i]=='1')ones++;
        else twos++;
    }
    int avg=n/3;
    for(int i=s.length()-1;i>=0 && ziros>avg;i--){
            if(s[i]=='0' && twos<avg){s[i]='2';twos++;ziros--;}
            else if(s[i]=='0' && ones<avg){s[i]='1';ones++;ziros--;};
    }
    for(int i=0;i<s.length() && ziros<avg;i++){
            if(s[i]=='1' && ones>avg){s[i]='0';ones--;ziros++;}
            else if(s[i]=='2' && twos>avg){s[i]='0';twos--;ziros++;};
    }
    for(int i=0;i<s.length()&& ones<avg;i++){
        if(s[i]=='2'){s[i]='1';ones++;twos--;}
    }
    for(int i=s.length()-1;i>=0 && ones>avg;i--){
        if(s[i]=='1'){s[i]='2';ones--;twos++;}
    }
        cout<<s;
}
