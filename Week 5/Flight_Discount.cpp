#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);\
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    dist[1][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto [cost, u, used] = pq.top();
        pq.pop();
        if (dist[u][used] < cost) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v][used] > cost + w) {
                dist[v][used] = cost + w;
                pq.push({dist[v][used], v, used});
            }
            if (used == 0 && dist[v][1] > cost + w / 2) {
                dist[v][1] = cost + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }
    cout << dist[n][1] << '\n';
    return 0;
}
