#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                cout << "NO\n";
                return 0;
            }
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "YES" : "NO") << '\n';
    return 0;
}