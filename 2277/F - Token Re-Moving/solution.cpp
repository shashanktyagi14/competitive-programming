#include <bits/stdc++.h>
using namespace std;
 
static const int MOD = 998244353;
 
struct DSU {
    vector<int> parent, sz, lazy, diff;
 
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        lazy.assign(n + 1, 0);
        diff.assign(n + 1, 0);
 
        iota(parent.begin(), parent.end(), 0);
    }
 
    int find(int x) {
        if (parent[x] == x) return x;
 
        int p = parent[x];
 
        parent[x] = find(p);
 
        diff[x] += diff[p];
        if (diff[x] >= MOD) diff[x] -= MOD;
 
        return parent[x];
    }
 
    void addComponent(int x, int val) {
        int r = find(x);
 
        lazy[r] += val;
        if (lazy[r] >= MOD) lazy[r] -= MOD;
    }
 
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
 
        if (a == b) return;
 
        if (sz[a] < sz[b]) swap(a, b);
 
        parent[b] = a;
 
        diff[b] = lazy[b] - lazy[a];
        if (diff[b] < 0) diff[b] += MOD;
 
        sz[a] += sz[b];
    }
 
    int getValue(int x) {
        int r = find(x);
 
        int res = lazy[r] + diff[x];
        if (res >= MOD) res -= MOD;
 
        return res;
    }
};
 
void solve() {
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n + 1);
 
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> a(n + 1), p(n);
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
 
    vector<int> parent(n + 1, 0);
    vector<int> order;
 
    order.reserve(n);
 
    parent[1] = -1;
    order.push_back(1);
 
    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
 
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
 
            parent[v] = u;
            order.push_back(v);
        }
    }
 
    vector<int> sub(n + 1, 0);
 
    for (int u = 1; u <= n; u++) {
        sub[u] = a[u];
    }
 
    for (int i = n - 1; i > 0; i--) {
        int u = order[i];
 
        sub[parent[u]] += sub[u];
 
        if (sub[parent[u]] >= MOD) {
            sub[parent[u]] -= MOD;
        }
    }
 
    int total = sub[1];
 
    DSU dsu(n);
 
    vector<char> active(n + 1, false);
 
    for (int i = n - 1; i >= 0; i--) {
        int u = p[i];
 
        for (int v : adj[u]) {
            if (!active[v]) continue;
 
            int sideSum;
 
            if (parent[u] == v) {
                sideSum = sub[u];
            } else {
                sideSum = total - sub[v];
 
                if (sideSum < 0) {
                    sideSum += MOD;
                }
            }
 
            dsu.addComponent(v, sideSum);
        }
 
        active[u] = true;
 
        dsu.parent[u] = u;
        dsu.sz[u] = 1;
        dsu.lazy[u] = 0;
        dsu.diff[u] = 0;
 
        for (int v : adj[u]) {
            if (active[v]) {
                dsu.unite(u, v);
            }
        }
    }
 
    for (int r = 1; r <= n; r++) {
        int ans = total + dsu.getValue(r);
 
        if (ans >= MOD) {
            ans -= MOD;
        }
 
        cout << ans << (r == n ? '
' : ' ');
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