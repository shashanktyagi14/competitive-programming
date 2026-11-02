#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        int len = (n % 3 == 0 ? n - 1 : n);
 
        vector<int> a;
        for (int v = 2 * n; (int)a.size() < len; v -= 2) {
            a.push_back(v);
        }
 
        cout << 3 * len << '
';
 
        bool first = true;
        for (int rep = 0; rep < 3; rep++) {
            for (int v : a) {
                if (!first) cout << ' ';
                cout << v;
                first = false;
            }
        }
        cout << '
';
    }
 
    return 0;
}