#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> grid(n, vector<long long>(m));
    for (auto &row : grid)
        for (auto &x : row) cin >> x;

    int sr, sc;
    long long newColor;
    cin >> sr >> sc >> newColor;
    --sr;
    --sc;

    if (sr < 0 || sr >= n || sc < 0 || sc >= m) return 0;

    long long oldColor = grid[sr][sc];
    if (oldColor == newColor) {
        for (auto &row : grid) {
            for (int j = 0; j < m; ++j) {
                if (j) cout << ' ';
                cout << row[j];
            }
            cout << '\n';
        }
        return 0;
    }

    stack<pair<int, int>> st;
    st.push({sr, sc});
    grid[sr][sc] = newColor;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    while (!st.empty()) {
        auto [r, c] = st.top();
        st.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] != oldColor) continue;
            grid[nr][nc] = newColor;
            st.push({nr, nc});
        }
    }

    for (auto &row : grid) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << ' ';
            cout << row[j];
        }
        cout << '\n';
    }
    return 0;
}