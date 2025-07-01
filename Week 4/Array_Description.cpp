#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    vector<int> prev(m + 2, 0), curr(m + 2, 0);

    // Base case
    if (arr[0] == 0) {
        for (int val = 1; val <= m; ++val) prev[val] = 1;
    } else {
        prev[arr[0]] = 1;
    }

    // Fill DP table
    for (int i = 1; i < n; ++i) {
        fill(curr.begin(), curr.end(), 0);
        for (int val = 1; val <= m; ++val) {
            if (arr[i] == 0 || arr[i] == val) {
                curr[val] = (prev[val] + prev[val - 1] + prev[val + 1]) % MOD;
            }
        }
        swap(prev, curr);
    }

    // Result: sum of all valid values at last position
    int ans = 0;
    for (int val = 1; val <= m; ++val) {
        ans = (ans + prev[val]) % MOD;
    }
    cout << ans << "\n";
}

