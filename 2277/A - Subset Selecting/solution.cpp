#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, k;
        cin >> n >> k;
 
        vector<int> cnt(n + 1, 0);
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
 
        int available = 0;
        int ans = n + 1;
 
        for (int i = 0; i <= n; i++) {
            available += cnt[i];
 
            if (cnt[i] == 0 || available < k) {
                ans = i;
                break;
            }
 
            available -= k;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}