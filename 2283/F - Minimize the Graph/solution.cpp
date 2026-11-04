#include <bits/stdc++.h>
using namespace std;
 
struct Fenwick {
    int n;
    vector<int> bit;
 
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
 
    void add(int x) {
        for (; x <= n; x += x & -x)
            ++bit[x];
    }
 
    int sum(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x)
            res += bit[x];
        return res;
    }
 
    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> l(n + 1), r(n + 1);
 
    for (int i = 2; i <= n; ++i)
        cin >> l[i] >> r[i];
 
    vector<int> parent(n + 2), nxt(n + 1, n + 1);
    iota(parent.begin(), parent.end(), 0);
 
    auto find = [&](int x) {
        int y = x;
 
        while (parent[y] != y)
            y = parent[y];
 
        while (parent[x] != x) {
            int z = parent[x];
            parent[x] = y;
            x = z;
        }
 
        return y;
    };
 
    for (int i = 2; i <= n; ++i) {
        int x = find(l[i]);
 
        while (x <= r[i]) {
            nxt[x] = i;
            parent[x] = find(x + 1);
            x = find(x);
        }
    }
 
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
 
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return nxt[a] > nxt[b];
    });
 
    vector<int> queries;
 
    for (int i = 2; i <= n; ++i)
        queries.push_back(i);
 
    sort(queries.begin(), queries.end(), [&](int a, int b) {
        return r[a] > r[b];
    });
 
    Fenwick fw(n);
 
    int ptr = 0;
    long long ans = 0;
 
    for (int i : queries) {
        while (ptr < n && nxt[ord[ptr]] > r[i]) {
            fw.add(ord[ptr]);
            ++ptr;
        }
 
        ans += fw.query(l[i], r[i]);
    }
 
    cout << ans << '
';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int noTsts;
    cin >> noTsts;
 
    while (noTsts--) {
        solve();
    }
 
    return 0;
}