#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
const int N = 5000;
 
int bell[N + 1], dp[N + 1];
 
void precompute() {
    vector<int> prv(N + 1), cur(N + 1);
 
    prv[0] = bell[0] = 1;
 
    for (int i = 1; i <= N; ++i) {
        cur[0] = prv[i - 1];
        bell[i] = cur[0];
 
        for (int j = 1; j <= i; ++j) {
            cur[j] = cur[j - 1] + prv[j - 1];
            if (cur[j] >= MOD) cur[j] -= MOD;
        }
 
        prv.swap(cur);
    }
 
    dp[0] = 1;
    dp[1] = 0;
 
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 2];
 
        if (i >= 3) {
            dp[i] += dp[i - 3];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
}
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
 
    int cnt0 = 0, cnt1 = 0;
    long long ways = 1;
 
    int len = 1;
 
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            ++len;
        } else {
            if (len == 1) {
                if (s[i - 1] == '0') ++cnt0;
                else ++cnt1;
            } else {
                ways = ways * dp[len] % MOD;
            }
 
            len = 1;
        }
    }
 
    if (len == 1) {
        if (s[n - 1] == '0') ++cnt0;
        else ++cnt1;
    } else {
        ways = ways * dp[len] % MOD;
    }
 
    ways = ways * bell[cnt0] % MOD;
    ways = ways * bell[cnt1] % MOD;
 
    int ans = 2 * n - cnt0 - cnt1;
 
    cout << ans << ' ' << ways << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    precompute();
 
    int noTsts;
    cin >> noTsts;
 
    while (noTsts--) {
        solve();
    }
 
    return 0;
}