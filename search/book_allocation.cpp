#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> pages(n);
    long long low = 0, high = 0;
    for (auto &x : pages) {
        cin >> x;
        low = max(low, x);
        high += x;
    }

    if (k <= 0 || k > n) {
        cout << -1 << '\n';
        return 0;
    }

    auto feasible = [&](long long limit) {
        int students = 1;
        long long current = 0;
        for (long long x : pages) {
            if (current + x > limit) {
                ++students;
                current = x;
            } else {
                current += x;
            }
        }
        return students <= k;
    };

    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (feasible(mid)) high = mid;
        else low = mid + 1;
    }

    cout << low << '\n';
    return 0;
}