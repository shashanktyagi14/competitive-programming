#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n), answer(n, 1);
    for (auto &x : a) cin >> x;

    long long prefix = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = prefix;
        prefix *= a[i];
    }

    long long suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= suffix;
        suffix *= a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}