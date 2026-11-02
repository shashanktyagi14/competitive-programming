#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long candidate = 0;
    int balance = 0;
    for (long long x : a) {
        if (balance == 0) candidate = x, balance = 1;
        else if (x == candidate) ++balance;
        else --balance;
    }

    int count = 0;
    for (long long x : a) count += (x == candidate);
    cout << (count > n / 2 ? candidate : -1) << '\n';
    return 0;
}