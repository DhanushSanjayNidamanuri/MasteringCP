#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

string path = "";
pair<int, int> start, end_pos;

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}

string reconstruct_path(pair<int,int> end) {
    string path = "";
    pair<int, int> cur = end;

    while (cur != start) {
        pair<int, int> p = parent[cur.first][cur.second];
        if (p.first == cur.first - 1) path += 'D'; // came from up
        else if (p.first == cur.first + 1) path += 'U'; // came from down
        else if (p.second == cur.second - 1) path += 'R'; // came from left
        else path += 'L'; // came from right
        cur = p;
    }
    reverse(path.begin(), path.end());
    return path;
}

void bfs() {
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (make_pair(x, y) == end_pos) {
            cout << "YES\n";
            string res = reconstruct_path(end_pos);
            cout << res.length() << "\n" << res << "\n";
            return;
        }

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    cout << "NO\n";
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end_pos = {i, j};
        }
    }

    bfs();
    return 0;
}
