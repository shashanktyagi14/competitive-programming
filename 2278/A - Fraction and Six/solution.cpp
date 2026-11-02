#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        string p, q;
        cin >> p >> q;
 
        int cnt[26] = {0};
 
        for (int i = 0; i < n; i++) {
            cnt[p[i] - 'a']++;
        }
 
        for (int i = 0; i < m; i++) {
            cnt[q[i] - 'a']--;
        }
 
        if (cnt['s' - 'a'] == 1 &&
            cnt['i' - 'a'] == 1 &&
            cnt['x' - 'a'] == 1) {
 
            bool ok = true;
 
            for (int i = 0; i < 26; i++) {
                if (i != ('s' - 'a') &&
                    i != ('i' - 'a') &&
                    i != ('x' - 'a') &&
                    cnt[i] != 0) {
                    ok = false;
                    break;
                }
            }
 
            if (ok) cout << "YES
";
            else cout << "NO
";
        }
        else {
            cout << "NO
";
        }
    }
 
    return 0;
}