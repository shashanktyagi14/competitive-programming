#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int k;
        cin >> k;
 
        int tree = 0, node = 1;
 
        for (int i = 1; i <= k; i++) {
            int n;
            cin >> n;
 
            vector<int> deg(n + 1, 0);
            vector<int> nei(n + 1, 0);
 
            for (int j = 0; j < n - 1; j++) {
                int u, v;
                cin >> u >> v;
 
                deg[u]++;
                deg[v]++;
 
                nei[u] = v;
                nei[v] = u;
            }
 
            if (tree == 0 && n > 1) {
                for (int j = 1; j <= n; j++) {
                    if (deg[j] == 1) {
                        tree = i;
                        node = nei[j];
                        break;
                    }
                }
            }
        }
 
        if (tree == 0) {
            tree = 1;
            node = 1;
        }
 
        for (int i = 1; i <= k; i++) {
            if (i != tree) {
                cout << tree << " " << node << " "
                     << i << " " << 1 << '
';
            }
        }
    }
 
    return 0;
}