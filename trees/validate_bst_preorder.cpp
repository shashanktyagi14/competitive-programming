#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> preorder(n);
    for (auto &x : preorder) cin >> x;

    unordered_set<long long> seen;
    vector<long long> st;
    optional<long long> lower;
    bool valid = true;

    for (long long x : preorder) {
        if (!seen.insert(x).second || (lower && x <= *lower)) {
            valid = false;
            break;
        }

        while (!st.empty() && x > st.back()) {
            lower = st.back();
            st.pop_back();
        }
        st.push_back(x);
    }

    cout << (valid ? "YES" : "NO") << '\n';
    return 0;
}