#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const ll MOD = 998244353;
 
ll cost(ll x) {
    ll res = 4 * x;
 
    for (int i = 0; x; i++, x >>= 1) {
        if (x & 1) res += i + 1;
    }
 
    return res;
}
 
ll f(ll n) {
    if (n <= 1) return n;
 
    ll need = n / 2;
    ll lo = 0, hi = (1LL << 58);
 
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
 
        if (2 * mid - __builtin_popcountll(mid) >= need) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
 
    ll best = cost(lo);
 
    for (ll p = (lo / 16 + 1) * 16; p <= lo + 427; p += 16) {
        best = min(best, cost(p));
    }
 
    return best - n;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        ll l, r;
        cin >> l >> r;
 
        ll ans = 0;
 
        for (ll n = l; n <= r; n++) {
            ans = (ans + f(n)) % MOD;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}