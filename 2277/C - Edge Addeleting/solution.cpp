#include <bits/stdc++.h>
using namespace std;
 
const int LOG = 20;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<vector<int>> adj(n + 1);
 
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        vector<array<int, LOG>> up(n + 1);
        vector<int> dep(n + 1), rootChild(n + 1);
        vector<int> st = {1};
 
        up[1].fill(1);
        rootChild[1] = 1;
 
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
 
            for (int v : adj[u]) {
                if (v == up[u][0]) continue;
 
                up[v][0] = u;
                dep[v] = dep[u] + 1;
                rootChild[v] = (u == 1 ? v : rootChild[u]);
 
                for (int j = 1; j < LOG; j++) {
                    up[v][j] = up[up[v][j - 1]][j - 1];
                }
 
                st.push_back(v);
            }
        }
 
        auto lca = [&](int u, int v) {
            if (dep[u] < dep[v]) swap(u, v);
 
            int d = dep[u] - dep[v];
 
            for (int j = 0; j < LOG; j++) {
                if (d & (1 << j)) {
                    u = up[u][j];
                }
            }
 
            if (u == v) return u;
 
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }
 
            return up[u][0];
        };
 
        int ans = dep[n];
 
        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
 
            if (rootChild[v] == rootChild[n]) {
                int w = lca(v, n);
                int dist = dep[v] + dep[n] - 2 * dep[w];
                ans = max(ans, dist + 1);
            }
        }
 
        cout << ans << '
';
    }
 
    return 0;
}