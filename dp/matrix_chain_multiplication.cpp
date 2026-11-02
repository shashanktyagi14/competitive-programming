#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;

void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> p(n + 1);
    for (auto &x : p) cin >> x;

    const i128 INF = (i128)1 << 120;
    vector<vector<i128>> dp(n, vector<i128>(n));
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l; k < r; ++k) {
                i128 cost = dp[l][k] + dp[k + 1][r]
                          + (i128)p[l] * p[k + 1] * p[r + 1];
                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }

    print_i128(n == 0 ? 0 : dp[0][n - 1]);
    cout << '\n';
    return 0;
}