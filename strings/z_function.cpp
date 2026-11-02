#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> z(n);
    int left = 0, right = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= right) z[i] = min(right - i + 1, z[i - left]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << z[i];
    }
    cout << '\n';
    return 0;
}