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
 
        vector<int> a(n), pos(n);
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
 
        int p = n - k + 1;
 
        vector<int> has(n + 1, 0);
 
        for (int i = 0; i < p; i++) {
            has[a[i]] = 1;
        }
 
        int mex = 0;
 
        while (has[mex]) {
            mex++;
        }
 
        if (mex == p) {
            cout << -1 << '
';
            continue;
        }
 
        int q = mex + 1;
 
        while (q < p && has[q]) {
            q++;
        }
 
        int i = 0;
 
        while (i < p && a[i] < q) {
            i++;
        }
 
        int j = pos[mex];
 
        cout << i + 1 << " " << j + 1 << '
';
    }
 
    return 0;
}