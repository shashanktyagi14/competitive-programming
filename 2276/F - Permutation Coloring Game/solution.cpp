#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
 
void upd(int &x, int y) {
    x = min(x, y);
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
 
    vector<bool> vis(n, false);
    vector<int> len;
 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int cur = i, cnt = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                cnt++;
                cur = p[cur];
            }
            len.push_back(cnt);
        }
    }
 
    sort(len.rbegin(), len.rend());
 
    if (k == 1) {
        if (len[0] >= 3)
            cout << "Bob
";
        else if (len[0] == 1 || n % 2 == 1)
            cout << "Alice
";
        else
            cout << "Bob
";
    } else if (len[0] > k + 1) {
        cout << "Bob
";
    } else if (len[0] == k + 1) {
        if (len.size() > 1 && len[1] == k + 1) {
            cout << "Bob
";
        } else {
            int must_remove = 0, cnt1 = 0;
 
            for (int i = 1; i < (int)len.size(); i++) {
                if (len[i] > 1)
                    must_remove += len[i];
                else
                    cnt1++;
            }
 
            int alice_move = must_remove + cnt1 % (k + 1);
 
            cout << (alice_move > k || alice_move == 0 ? "Bob
" : "Alice
");
        }
    } else {
        int m = min((int)len.size(), 2 * k);
 
        vector<vector<vector<int>>> dp(
            m + 1,
            vector<vector<int>>(k + 1, vector<int>(k + 1, INF))
        );
 
        dp[0][0][0] = 0;
 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= k; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INF)
                        continue;
 
                    if (j + len[i] <= k)
                        upd(dp[i + 1][j + len[i]][c + 1], dp[i][j][c]);
 
                    int bob_can = (i - c < k);
                    upd(dp[i + 1][j][c],
                        dp[i][j][c] + (bob_can ? len[i] - 1 : 0));
                }
            }
        }
 
        bool alice_win = false;
 
        for (int j = 0; j <= k; j++) {
            for (int c = 0; c <= k; c++) {
                if (dp[m][j][c] <= k)
                    alice_win = true;
            }
        }
 
        cout << (alice_win ? "Alice
" : "Bob
");
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}