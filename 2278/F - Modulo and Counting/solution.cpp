#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 998244353;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<long long> dp(m + 1, 0);
        vector<long long> ndp(m + 1, 0);
        vector<long long> pref(m + 1, 0);
 
        dp[0] = 1;
 
        long long ans = dp[m];
 
        for (int k = 1; k < n; k++) {
 
            pref[0] = dp[0];
 
            for (int i = 1; i <= m; i++) {
                pref[i] = (pref[i - 1] + dp[i]) % MOD;
            }
 
            for (int i = 0; i <= m; i++) {
                int l = i / 2;
 
                ndp[i] = pref[i];
 
                if (l > 0) {
                    ndp[i] = (ndp[i] - pref[l - 1] + MOD) % MOD;
                }
            }
 
            dp = ndp;
 
            ans = (ans + dp[m]) % MOD;
        }
 
        cout << ans << "
";
    }
 
    return 0;
}