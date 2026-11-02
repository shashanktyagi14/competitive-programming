#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
 
        vector<array<int, 10>> nxt(n + 1);
        nxt[n].fill(n);
 
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - '0'] = i;
        }
 
        auto getEnd = [&](int l, const string& pat) {
            int p = l;
 
            for (char c : pat) {
                p = nxt[p][c - '0'];
 
                if (p == n) return n;
 
                ++p;
            }
 
            return p - 1;
        };
 
        vector<long long> da(n + 1, 0), db(n + 1, 0);
 
        auto add = [&](int l, int r, long long a, long long b) {
            if (l > r) return;
 
            da[l] += a;
            da[r + 1] -= a;
 
            db[l] += b;
            db[r + 1] -= b;
        };
 
        for (int l = 0; l < n; ++l) {
            int L = getEnd(l, "2025");
            int E = getEnd(l, "2026");
 
            if (L == n || L >= E) continue;
 
            int R = E - 1;
            long long cnt = R - L + 1;
 
            add(l, L, 0, cnt);
            add(L + 1, R, -1, R + 1LL);
        }
 
        long long a = 0, b = 0;
 
        for (int i = 0; i < n; ++i) {
            a += da[i];
            b += db[i];
 
            long long bad = a * i + b;
            long long total = 1LL * (i + 1) * (n - i);
 
            cout << total - bad << (i + 1 == n ? '
' : ' ');
        }
    }
 
    return 0;
}