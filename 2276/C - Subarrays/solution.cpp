#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, k;
        cin >> n >> k;
 
        vector<int> pref(n + 1, 0);
 
        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            pref[i] = (pref[i - 1] + x % k) % k;
        }
 
        vector<long long> freq(k, 0);
        long long ans = 0;
 
        for (int i = k + 1; i <= n; i++) {
            freq[pref[i - k - 1]]++;
            ans += freq[pref[i]];
        }
 
        cout << ans << '
';
    }
 
    return 0;
}