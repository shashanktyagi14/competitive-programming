#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> last(256, -1);
    int left = 0, answer = 0;

    for (int right = 0; right < (int)s.size(); ++right) {
        unsigned char c = s[right];
        left = max(left, last[c] + 1);
        last[c] = right;
        answer = max(answer, right - left + 1);
    }

    cout << answer << '\n';
    return 0;
}