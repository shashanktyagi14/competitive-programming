#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<array<long long, 3>> answer;
    for (int i = 0; i < n; ++i) {
        if (i && a[i] == a[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            long long sum = a[i] + a[left] + a[right];
            if (sum < 0) ++left;
            else if (sum > 0) --right;
            else {
                answer.push_back({a[i], a[left], a[right]});
                long long x = a[left], y = a[right];
                while (left < right && a[left] == x) ++left;
                while (left < right && a[right] == y) --right;
            }
        }
    }

    cout << answer.size() << '\n';
    for (auto triplet : answer)
        cout << triplet[0] << ' ' << triplet[1] << ' ' << triplet[2] << '\n';
    return 0;
}