#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    int p = 1;
    while (p * 2 <= n) p *= 2;
 
    int s;
    if (n % 4 == 0) s = n;
    else if (n % 4 == 1) s = 1;
    else if (n % 4 == 2) s = n + 1;
    else s = 0;
 
    int m = 4 * p - 2;
    int z = s ^ m;
 
    if (__builtin_popcount(z) & 1) {
        m++;
        z = s ^ m;
    }
 
    int y = 0, cur = 0;
 
    for (int b = 0; b < 20; b++) {
        cur ^= (z >> b) & 1;
        if (cur) y |= (1 << b);
    }
 
    for (int i = 1; i <= n; i++) {
        int d = ((i & (i - 1)) == 0 && (y & i));
        cout << d << (i == n ? '
' : ' ');
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int noTsts;
    cin >> noTsts;
 
    while (noTsts--) solve();
 
    return 0;
}