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
        }
 
        sort(a.begin(), a.end());
 
        long long mid = a[n / 2];
        long long cost = 0;
 
        for (int i = 0; i < n; i++) {
            cost += abs(a[i] - mid);
        }
 
        long long ops = a[n - 1] - a[0];
 
        cout << cost << " " << ops << "
";
    }
 
    return 0;
}