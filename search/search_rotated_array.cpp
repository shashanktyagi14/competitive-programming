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

    int left = 0, right = n - 1, answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) {
            answer = mid;
            break;
        }

        if (a[left] <= a[mid]) {
            if (a[left] <= target && target < a[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (a[mid] < target && target <= a[right]) left = mid + 1;
            else right = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}