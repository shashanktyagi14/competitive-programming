#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<int> deg(n, 0);
 
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
 
            deg[u]++;
            deg[v]++;
        }
 
        bool isolated = false;
        int maxDegree = 0;
 
        for (int d : deg) {
            if (d == 0) isolated = true;
            maxDegree = max(maxDegree, d);
        }
 
        if (isolated) {
            cout << "Brain Melt
";
        } else if (m == n - 1 && maxDegree == n - 1) {
            cout << "2
";
        } else {
            cout << "Many
";
        }
    }
 
    return 0;
}