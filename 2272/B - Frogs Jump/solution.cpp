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
 
        string a, b;
        cin >> a >> b;
 
        int cnt = 0;
 
        for (int i = 0; i < n; i++) {
            if (a[i] == 'f') cnt++;
            if (b[i] == 'f') cnt++;
        }
 
        cout << cnt % 2 << '
';
    }
 
    return 0;
}