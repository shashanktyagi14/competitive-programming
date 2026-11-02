#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    auto it = lower_bound(a.begin(), a.end(), target);
    if (it == a.end() || *it != target) cout << -1 << '\n';
    else cout << (it - a.begin()) << '\n';
    return 0;
}