#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    if (n < 0) {
        cout << -1 << '\n';
        return 0;
    }

    long long root = sqrtl((long double)n);
    while ((__int128)(root + 1) * (root + 1) <= n) ++root;
    while ((__int128)root * root > n) --root;

    cout << root << '\n';
    return 0;
}