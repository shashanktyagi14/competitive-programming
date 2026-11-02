#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (auto &v : a) cin >> v;

    cout << lower_bound(a.begin(), a.end(), x) - a.begin() << ' '
         << upper_bound(a.begin(), a.end(), x) - a.begin() << '\n';
    return 0;
}