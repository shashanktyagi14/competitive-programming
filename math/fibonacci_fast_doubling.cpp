#include <bits/stdc++.h>
using namespace std;

static constexpr long long MOD = 1000000007LL;

pair<long long, long long> fib(unsigned long long n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib(n >> 1);
    long long two_b_minus_a = (2 * b % MOD - a + MOD) % MOD;
    long long c = (__int128)a * two_b_minus_a % MOD;
    long long d = ((__int128)a * a + (__int128)b * b) % MOD;

    if (n & 1) return {d, (c + d) % MOD};
    return {c, d};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;
    cout << fib(n).first << '\n';
    return 0;
}