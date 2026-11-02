#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<vector<int>> g(n + 1);
 
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    vector<int> par(n + 1, 0), order;
    order.push_back(1);
 
    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
 
        for (int v : g[u]) {
            if (v == par[u]) continue;
 
            par[v] = u;
            order.push_back(v);
        }
    }
 
    vector<int> down(n + 1, 0), up(n + 1, 0);
 
    for (int i = n - 1; i >= 1; i--) {
        int u = order[i];
        int cnt = 0;
 
        for (int v : g[u]) {
            if (par[v] == u && down[v] == 0) {
                cnt++;
            }
        }
 
        int children = (int)g[u].size() - 1;
        down[u] = (cnt > 0 || children % 2 == 0);
    }
 
    for (int u : order) {
        int cnt = 0;
 
        if (par[u] != 0 && up[u] == 0) {
            cnt++;
        }
 
        for (int v : g[u]) {
            if (par[v] == u && down[v] == 0) {
                cnt++;
            }
        }
 
        for (int v : g[u]) {
            if (par[v] != u) continue;
 
            int cur = cnt - (down[v] == 0);
 
            up[v] = (cur > 0 || (int)g[u].size() % 2 == 1);
        }
    }
 
    vector<int> ans;
 
    for (int u = 1; u <= n; u++) {
        int cnt = 0;
 
        if (par[u] != 0 && up[u] == 0) {
            cnt++;
        }
 
        for (int v : g[u]) {
            if (par[v] == u && down[v] == 0) {
                cnt++;
            }
        }
 
        bool win = (cnt > 0 || (int)g[u].size() % 2 == 1);
 
        if (!win) {
            ans.push_back(u);
        }
    }
 
    if (ans.empty()) {
        cout << "Alice
";
    } else {
        cout << "Bob
";
        cout << ans.size() << '
';
 
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
 
        cout << '
';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}