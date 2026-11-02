#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<string, vector<string>> groups;

    for (int i = 0; i < n; ++i) {
        string word, key;
        cin >> word;
        key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    cout << groups.size() << '\n';
    for (auto &[key, words] : groups) {
        for (int i = 0; i < (int)words.size(); ++i) {
            if (i) cout << ' ';
            cout << words[i];
        }
        cout << '\n';
    }
    return 0;
}