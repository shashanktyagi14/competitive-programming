#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;
    switch (n & 3ULL) {
        case 0: cout << n; break;
        case 1: cout << 1; break;
        case 2: cout << n + 1; break;
        default: cout << 0; break;
    }
    cout << '\n';
    return 0;
}