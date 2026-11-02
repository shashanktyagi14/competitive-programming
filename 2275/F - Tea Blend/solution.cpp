#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int MAXA = 1000000;
const int K = 7;
 
int spf[MAXA + 1];
using Key = array<int, K>;
 
void buildSPF() {
    for (int i = 2; i <= MAXA; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            if (1LL * i * i <= MAXA) {
                for (int j = i * i; j <= MAXA; j += i) {
                    if (spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
    }
}
 
Key getSignature(int x) {
    Key key{};
    int idx = 0;
 
    while (x > 1) {
        int p = spf[x];
        int parity = 0;
 
        while (x % p == 0) {
            x /= p;
            parity ^= 1;
        }
 
        if (parity)
            key[idx++] = p;
    }
 
    return key;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    buildSPF();
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<Key> sig(n);
        map<Key, ll> cnt;
 
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
 
            sig[i] = getSignature(x);
            ++cnt[sig[i]];
        }
 
        set<int> active;
        ll ans = 0;
 
        for (const Key &key : sig) {
            for (int p : key) {
                if (p == 0)
                    break;
 
                auto it = active.find(p);
 
                if (it == active.end())
                    active.insert(p);
                else
                    active.erase(it);
            }
 
            if (active.size() <= K) {
                Key cur{};
                int idx = 0;
 
                for (int p : active)
                    cur[idx++] = p;
 
                auto it = cnt.find(cur);
 
                if (it != cnt.end())
                    ans += it->second;
            }
        }
 
        cout << ans << '
';
    }
 
    return 0;
}