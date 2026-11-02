#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<long long> values;
    values.reserve(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        values.insert(x);
    }

    int answer = 0;
    for (long long x : values) {
        if (x != LLONG_MIN && values.count(x - 1)) continue;
        int length = 1;
        long long y = x;
        while (y != LLONG_MAX && values.count(y + 1)) {
            ++y;
            ++length;
        }
        answer = max(answer, length);
    }

    cout << answer << '\n';
    return 0;
}