#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    int left = 0, right = n - 1;
    while (left < right) {
        long long sum = a[left] + a[right];
        if (sum == target) {
            cout << left + 1 << ' ' << right + 1 << '\n';
            return 0;
        }
        if (sum < target) ++left;
        else --right;
    }

    cout << -1 << '\n';
    return 0;
}