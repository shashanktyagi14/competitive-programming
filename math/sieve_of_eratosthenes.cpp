#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n < 2) {
        cout << '\n';
        return 0;
    }

    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p <= n / p; ++p) {
        if (!prime[p]) continue;
        for (int multiple = p * p; multiple <= n; multiple += p)
            prime[multiple] = false;
    }

    bool first = true;
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }
    cout << '\n';
    return 0;
}