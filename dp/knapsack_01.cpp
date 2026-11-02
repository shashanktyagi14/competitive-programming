#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, capacity;
    cin >> n >> capacity;
    vector<int> weight(n);
    vector<long long> value(n);
    for (int &x : weight) cin >> x;
    for (auto &x : value) cin >> x;

    vector<long long> dp(capacity + 1);
    for (int i = 0; i < n; ++i) {
        for (int w = capacity; w >= weight[i]; --w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[capacity] << '\n';
    return 0;
}