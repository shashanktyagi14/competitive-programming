#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n + 1);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> st;
    long long answer = 0;
    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && h[st.back()] > h[i]) {
            long long height = h[st.back()];
            st.pop_back();
            int left = st.empty() ? -1 : st.back();
            long long width = i - left - 1;
            answer = max(answer, height * width);
        }
        st.push_back(i);
    }

    cout << answer << '\n';
    return 0;
}