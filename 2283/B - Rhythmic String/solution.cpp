#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int &x : a) cin >> x;
 
    int ans = n;
 
    for (int i = 0; i < n; i++) {
        int cnt = 0;
 
        for (int j = 0; j < n; j++) {
            if (a[j] % a[i] == 0) cnt++;
        }
 
        ans = min(ans, n - cnt);
    }
 
    cout << ans << '
';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) solve();
 
    return 0;
}