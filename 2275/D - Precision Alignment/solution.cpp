#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct Lab {
    ll sum;
    ll unlock;
    bool fixed;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
 
        vector<Lab> labs(n);
        ll mn = LLONG_MAX;
        ll fixedMin = LLONG_MAX;
 
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
 
            ll s = a + b + c;
            mn = min(mn, s);
 
            if (a > b || a > c || b > c) {
                labs[i] = {s, 0, false};
            } else if (a == b && b == c) {
                labs[i] = {s, 0, true};
                fixedMin = min(fixedMin, s);
            } else {
                ll d = min(b - a + 1, c - b + 1);
                labs[i] = {s, d, false};
            }
        }
 
        auto can = [&](ll target) -> bool {
            ll used = 0;
 
            for (const auto &lab : labs) {
                if (lab.fixed) {
                    if (target > lab.sum) {
                        return false;
                    }
                    continue;
                }
 
                if (target <= lab.sum) {
                    continue;
                }
 
                ll need = target - lab.sum + 2LL * lab.unlock;
 
                if (need > k - used) {
                    return false;
                }
 
                used += need;
            }
 
            return true;
        };
 
        ll lo = mn;
        ll hi = mn + k;
 
        if (fixedMin != LLONG_MAX) {
            hi = min(hi, fixedMin);
        }
 
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
 
            if (can(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
 
        cout << lo << '
';
    }
 
    return 0;
}