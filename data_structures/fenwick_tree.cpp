#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree (Binary Indexed Tree)
// Supports:
// 1) point update: add value at index i
// 2) prefix sum query: sum of values in [1..i]
// 3) range sum query: sum in [l..r]
//
// Works well for offline or online cumulative queries in O(log n).
class FenwickTree {
public:
    explicit FenwickTree(int n) : n_(n + 1), tree_(n + 1, 0) {}

    void add(int idx, long long delta) {
        for (int i = idx; i < (int)tree_.size(); i += i & -i) {
            tree_[i] += delta;
        }
    }

    long long prefix_sum(int idx) const {
        long long ans = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            ans += tree_[i];
        }
        return ans;
    }

    long long range_sum(int l, int r) const {
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }

private:
    int n_;
    vector<long long> tree_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1);
    FenwickTree bit(n);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        bit.add(i, arr[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // add value at position idx
            int idx;
            long long delta;
            cin >> idx >> delta;
            bit.add(idx, delta);
            arr[idx] += delta;
        } else if (type == 2) {
            // prefix sum query [1..idx]
            int idx;
            cin >> idx;
            cout << bit.prefix_sum(idx) << '\n';
        } else if (type == 3) {
            // range sum query [l..r]
            int l, r;
            cin >> l >> r;
            cout << bit.range_sum(l, r) << '\n';
        }
    }

    return 0;
}

/*
Example:
Input
5 6
1 2 3 4 5
1 3 10
2 5
3 2 4
1 1 -7
2 5
3 1 5

Output
35
11
28

Explanation:
Initial array = [1,2,3,4,5]
After adding 10 at index 3 -> [1,2,13,4,5]
Prefix sum to 5 = 1 + 2 + 13 + 4 + 5 = 25
Range sum [2..4] = 2 + 13 + 4 = 19
Then subtract 7 at index 1 -> [ -6, 2, 13, 4, 5 ]
Prefix sum to 5 = 18
Range sum [1..5] = 18
*/
