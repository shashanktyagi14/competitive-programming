#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    unordered_map<long long, long long> freq;
    freq.reserve(2 * n + 1);
    freq[0] = 1;

    long long pref = 0, answer = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        pref += x;
        if (freq.count(pref - k)) answer += freq[pref - k];
        ++freq[pref];
    }

    cout << answer << '\n';
    return 0;
}