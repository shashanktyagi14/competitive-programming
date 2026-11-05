#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    vector<int> freq(n, 0);

    for (long long &x : a) {
        cin >> x;
        if (0 <= x && x < n) ++freq[(int)x];
    }

    sort(a.begin(), a.end());

    int ptr = 0;
    long long available = 0;
    int mex = 0;

    for (int x = 0; x < n; ++x) {
        while (ptr < n && a[ptr] <= x) {
            ++ptr;
            ++available;
        }

        if (freq[x] == 0) break;
        if ((__int128)available < (__int128)k * (x + 1)) break;

        ++mex;
    }

    cout << mex << '\n';
    return 0;
}
