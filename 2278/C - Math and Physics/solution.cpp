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
 
        vector<int> a(n);
        long long sum = 0;
 
        bool ok = false;
        bool mid = false;
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
 
            sum += a[i];
 
            if (a[i] > 1) {
                ok = true;
 
                if (i > 0 && i < n - 1) {
                    mid = true;
                }
            }
        }
 
        if (!ok) {
            cout << -1 << "
";
        }
        else if (mid) {
            cout << sum - 1 << "
";
        }
        else {
            cout << sum - (n - 1) << "
";
        }
    }
 
    return 0;
}