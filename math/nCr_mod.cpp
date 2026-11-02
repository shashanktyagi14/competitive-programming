#include <bits/stdc++.h>
using namespace std;

static constexpr long long MOD = 1000000007LL;

long long mod_pow(long long a, long long e) {
    long long result = 1;
    while (e) {
        if (e & 1) result = result * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, r;
    cin >> n >> r;
    if (n < 0 || n >= MOD || r < 0 || r > n) {
        cout << 0 << '\n';
        return 0;
    }

    r = min(r, n - r);
    long long numerator = 1, denominator = 1;
    for (long long i = 1; i <= r; ++i) {
        numerator = numerator * ((n - r + i) % MOD) % MOD;
        denominator = denominator * i % MOD;
    }

    cout << numerator * mod_pow(denominator, MOD - 2) % MOD << '\n';
    return 0;
}