#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    if (b.size() > a.size()) swap(a, b);

    vector<int> dp(b.size() + 1);
    iota(dp.begin(), dp.end(), 0);

    for (int i = 1; i <= (int)a.size(); ++i) {
        int diagonal = dp[0];
        dp[0] = i;
        for (int j = 1; j <= (int)b.size(); ++j) {
            int old = dp[j];
            if (a[i - 1] == b[j - 1]) dp[j] = diagonal;
            else dp[j] = 1 + min({diagonal, dp[j], dp[j - 1]});
            diagonal = old;
        }
    }

    cout << dp.back() << '\n';
    return 0;
}