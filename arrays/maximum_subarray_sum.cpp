#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long x, current, answer;
    cin >> x;
    current = answer = x;

    for (int i = 1; i < n; ++i) {
        cin >> x;
        current = max(x, current + x);
        answer = max(answer, current);
    }

    cout << answer << '\n';
    return 0;
}