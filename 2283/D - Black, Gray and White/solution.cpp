#include <bits/stdc++.h>
using namespace std;
 
bool canGray(int x, int k, int n, const vector<vector<int>>& g) {
    vector<int> comp(n + 1, -1);
    vector<int> st;
 
    int id = 0;
 
    for (int v : g[x]) {
        if (comp[v] != -1) continue;
 
        comp[v] = id;
        st.push_back(v);
 
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
 
            for (int w : g[u]) {
                if (w == x || comp[w] != -1) continue;
 
                comp[w] = id;
                st.push_back(w);
            }
        }
 
        ++id;
    }
 
    int l = max(1, k - n);
    int r = (k - 1) / 2;
 
    for (int a = l; a <= r; ++a) {
        int b = k - a;
 
        if (comp[a] != comp[b]) {
            return true;
        }
    }
 
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int noTsts;
    cin >> noTsts;
 
    while (noTsts--) {
        int n;
        cin >> n;
 
        vector<vector<int>> g(n + 1);
 
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
 
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        if (n % 2 == 0) {
            cout << n + 1 << '
';
            continue;
        }
 
        int ans = n + 1;
 
        if (canGray(n, n, n, g)) {
            ans = n;
        }
        else if (canGray((n + 1) / 2, n + 1, n, g)) {
            ans = n + 1;
        }
        else if (canGray(1, n + 2, n, g)) {
            ans = n + 2;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}