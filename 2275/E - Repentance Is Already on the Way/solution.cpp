#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n), b(n);
 
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
 
        long long ans = 2LL * n - 1;
        long long fixed = 0;
 
        for (int i = 0; i < n - 1; i++) {
            fixed += (a[i + 1] == b[i]);
        }
 
        fixed += (a[n - 1] == b[n - 1]);
 
        long long suffix = 0;
 
        for (int i = 0; i < n - 1; i++) {
            suffix += (a[i] == b[i + 1]);
        }
 
        long long prefix = 0;
        long long best = suffix;
 
        for (int i = 0; i < n - 1; i++) {
            prefix += (a[i] == b[i]);
            suffix -= (a[i] == b[i + 1]);
            best = max(best, prefix + suffix);
        }
 
        cout << ans + fixed + best << '
';
    }
 
    return 0;
}