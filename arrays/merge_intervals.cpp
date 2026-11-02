#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long, long long>> intervals(n);
    for (auto &[l, r] : intervals) cin >> l >> r;
    sort(intervals.begin(), intervals.end());

    vector<pair<long long, long long>> merged;
    for (auto [l, r] : intervals) {
        if (merged.empty() || l > merged.back().second) {
            merged.push_back({l, r});
        } else {
            merged.back().second = max(merged.back().second, r);
        }
    }

    cout << merged.size() << '\n';
    for (auto [l, r] : merged) cout << l << ' ' << r << '\n';
    return 0;
}