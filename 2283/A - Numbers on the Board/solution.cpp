#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int l, r;
        cin >> l >> r;
 
        if (l <= 0 && r >= 0)
            cout << max(0, abs(l + r) - 1) << '
';
        else
            cout << r - l << '
';
    }
 
    return 0;
}