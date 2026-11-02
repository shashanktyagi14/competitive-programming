#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int &x : coins) cin >> x;

    const int INF = amount + 1;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        if (coin <= 0) continue;
        for (int sum = coin; sum <= amount; ++sum) {
            if (dp[sum - coin] != INF)
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
        }
    }

    cout << (dp[amount] == INF ? -1 : dp[amount]) << '\n';
    return 0;
}