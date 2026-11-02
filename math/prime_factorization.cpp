#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    if (n <= 0) {
        cout << "Input must be positive\n";
        return 0;
    }
    if (n == 1) {
        cout << "1^1\n";
        return 0;
    }

    bool first = true;
    for (long long p = 2; p <= n / p; ++p) {
        if (n % p != 0) continue;
        int exponent = 0;
        while (n % p == 0) {
            n /= p;
            ++exponent;
        }
        if (!first) cout << ' ';
        cout << p << '^' << exponent;
        first = false;
    }
    if (n > 1) {
        if (!first) cout << ' ';
        cout << n << "^1";
    }
    cout << '\n';
    return 0;
}