#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
 
        int n = x + y + z;
 
        string ans = "";
 
        if (y >= z) {
            ans = string(n, 'R');
        }
        else if (z >= x) {
            ans = string(n, 'S');
        }
        else {
            ans = string(n, 'P');
        }
 
        cout << ans << "
";
    }
 
    return 0;
}