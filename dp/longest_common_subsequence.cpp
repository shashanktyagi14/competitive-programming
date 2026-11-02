#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    if (b.size() > a.size()) swap(a, b);

    vector<int> dp(b.size() + 1);
    for (char x : a) {
        int diagonal = 0;
        for (int j = 1; j <= (int)b.size(); ++j) {
            int old = dp[j];
            if (x == b[j - 1]) dp[j] = diagonal + 1;
            else dp[j] = max(dp[j], dp[j - 1]);
            diagonal = old;
        }
    }

    cout << dp.back() << '\n';
    return 0;
}