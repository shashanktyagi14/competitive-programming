#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1), diff(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    while (q--) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }

    long long add = 0;
    for (int i = 1; i <= n; ++i) {
        add += diff[i];
        if (i > 1) cout << ' ';
        cout << a[i] + add;
    }
    cout << '\n';
    return 0;
}