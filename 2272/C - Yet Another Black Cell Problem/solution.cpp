#include <bits/stdc++.h>
using namespace std;
 
bool check(vector<int> &a, int n, int x, int k) {
    vector<int> bad(n, 0);
 
    bad[0] = (a[1] - a[0] > k);
    bad[n - 1] = (a[n - 1] - a[n - 2] > k);
 
    for (int i = 1; i < n - 1; i++) {
        if (a[i] - a[i - 1] > k &&
            a[i + 1] - a[i] > k) {
            bad[i] = 1;
        }
    }
 
    int need = 0;
 
    for (int i = 0; i < n; i++) {
        need += bad[i];
    }
 
    for (int i = 0; i < n - 1; i++) {
        if (bad[i] && bad[i + 1] &&
            1LL * (a[i + 1] - a[i]) <= 2LL * k) {
            need--;
            i++;
        }
    }
 
    return need <= x;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, x;
        cin >> n >> x;
 
        vector<int> a(n);
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        int l = 1;
        int r = a[n - 1] - a[0];
 
        while (l < r) {
            int mid = l + (r - l) / 2;
 
            if (check(a, n, x, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
 
        cout << l << '
';
    }
 
    return 0;
}