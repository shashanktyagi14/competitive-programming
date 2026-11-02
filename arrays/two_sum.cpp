#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;

    unordered_map<long long, int> first;
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        long long need = target - x;
        if (first.count(need)) {
            cout << first[need] << ' ' << i << '\n';
            return 0;
        }
        if (!first.count(x)) first[x] = i;
    }

    cout << -1 << '\n';
    return 0;
}