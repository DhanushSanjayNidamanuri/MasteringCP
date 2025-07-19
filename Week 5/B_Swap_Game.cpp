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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int cnt_less = 0, cnt_eq = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[0]) cnt_less++;
        if (a[i] == a[0]) cnt_eq++;
    }

    if (cnt_less == 0 && cnt_eq == 0) {
        // a[0] is the unique minimum
        if ((a[0] - 1) % 2 == 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    } else {
        // Alice can avoid the smallest value
        cout << "Alice\n";
    }
}

int32_t main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
