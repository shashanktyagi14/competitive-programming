#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<long long> a(n);
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
 
            if (i % 2 == 0) {
                a[i] = -a[i];
            }
        }
 
        sort(a.begin(), a.end());
 
        long long ans = 0;
 
        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                ans -= a[i];
            }
            else {
                ans += a[i];
            }
        }
 
        cout << ans << "
";
    }
 
    return 0;
}