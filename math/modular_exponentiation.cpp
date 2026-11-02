#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long a, long long b, long long mod) {
    a %= mod;
    if (a < 0) a += mod;
    long long result = 1 % mod;
    while (b > 0) {
        if (b & 1) result = (__int128)result * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, mod;
    cin >> a >> b >> mod;
    if (b < 0 || mod <= 0) {
        cout << -1 << '\n';
        return 0;
    }
    cout << mod_pow(a, b, mod) << '\n';
    return 0;
}