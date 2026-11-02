#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    __int128 l = (__int128)(a / g) * b;

    cout << g << ' ';
    if (l > LLONG_MAX || l < LLONG_MIN) cout << "OVERFLOW\n";
    else cout << (long long)l << '\n';
    return 0;
}