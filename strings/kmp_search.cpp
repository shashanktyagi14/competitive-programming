#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;
    int n = (int)text.size(), m = (int)pattern.size();

    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) ++j;
        pi[i] = j;
    }

    vector<int> positions;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) ++j;
        if (j == m) {
            positions.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    cout << positions.size() << '\n';
    for (int i = 0; i < (int)positions.size(); ++i) {
        if (i) cout << ' ';
        cout << positions[i];
    }
    cout << '\n';
    return 0;
}