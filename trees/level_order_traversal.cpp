#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vector<vector<int>> levels;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if ((int)levels.size() <= dist[u]) levels.resize(dist[u] + 1);
        levels[dist[u]].push_back(u);

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << levels.size() << '\n';
    for (auto &level : levels) {
        for (int i = 0; i < (int)level.size(); ++i) {
            if (i) cout << ' ';
            cout << level[i];
        }
        cout << '\n';
    }
    return 0;
}