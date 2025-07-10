#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N], path, parent(N);
vector<bool> visited(N, false);
int start = -1, endNode = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;
        if (visited[neighbor]) {
            start = neighbor;
            endNode = node;
            return true;
        } else {
            parent[neighbor] = node;
            if (dfs(neighbor, node)) return true;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            parent[i] = -1;
            if (dfs(i, -1)) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endNode; v != start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(start); // to close the cycle


        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}

