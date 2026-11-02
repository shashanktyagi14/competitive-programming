#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    int sr, sc, tr, tc;
    cin >> sr >> sc >> tr >> tc;
    --sr; --sc; --tr; --tc;

    if (sr < 0 || sr >= n || sc < 0 || sc >= m ||
        tr < 0 || tr >= n || tc < 0 || tc >= m ||
        grid[sr][sc] == '#' || grid[tr][tc] == '#') {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == tr && c == tc) break;

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    cout << dist[tr][tc] << '\n';
    return 0;
}