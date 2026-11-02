#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 998244353;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<vector<int>> g(n);
 
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
 
            u--;
            v--;
 
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        string x, y;
        cin >> x >> y;
 
        vector<int> par(n, -1);
        vector<int> carry(n, 0);
        vector<int> order;
 
        order.push_back(0);
 
        int pos = 0;
        bool ok = true;
 
        long long ans = 0;
        long long pw = 1;
 
        while (pos < (int)order.size()) {
            int last = order.size();
            int bit = -1;
 
            for (int i = pos; i < last; i++) {
                int v = order[i];
 
                int need = (x[v] - '0') ^ (y[v] - '0') ^ carry[v];
 
                if (bit == -1) {
                    bit = need;
                }
                else if (bit != need) {
                    ok = false;
                    break;
                }
            }
 
            if (!ok) {
                break;
            }
 
            if (bit == 1) {
                ans = (ans + pw) % mod;
            }
 
            for (int i = pos; i < last; i++) {
                int v = order[i];
 
                for (int u : g[v]) {
                    if (u == par[v]) {
                        continue;
                    }
 
                    par[u] = v;
 
                    carry[u] = (bit + (x[v] - '0') + carry[v]) / 2;
 
                    order.push_back(u);
                }
            }
 
            pos = last;
            pw = (pw * 2) % mod;
        }
 
        if (!ok) {
            cout << -1 << "
";
        }
        else {
            cout << ans << "
";
        }
    }
 
    return 0;
}