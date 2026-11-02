#include <bits/stdc++.h>
using namespace std;
 
vector<int> getWrites(string s) {
    vector<int> v;
 
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'W') {
            v.push_back(i + 1);
        }
    }
 
    return v;
}
 
vector<long long> getAns(string s, int otherLen,
                         vector<int> &writes,
                         vector<int> &gaps,
                         vector<long long> &pref) {
    vector<long long> ans;
    int last = 0;
    int lastOther = 0;
 
    if (!writes.empty()) {
        lastOther = writes.back();
    }
 
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'W') {
            last = i + 1;
        } else {
            long long res;
 
            if (last > 0) {
                if (writes.empty()) {
                    res = otherLen + 1LL;
                } else {
                    int d = i - last;
                    res = max(1LL * otherLen,
                              1LL * lastOther + d) + 1;
                }
            } else {
                int z = i + 1;
 
                if (writes.empty()) {
                    res = 1;
                } else {
                    int p = upper_bound(gaps.begin(), gaps.end(), z)
                            - gaps.begin();
 
                    long long sum = pref[p]
                                  + 1LL * (gaps.size() - p) * z;
 
                    res = 1LL + z + sum;
                }
            }
 
            ans.push_back(res);
        }
    }
 
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        string s, u;
        cin >> s >> u;
 
        vector<int> ws = getWrites(s);
        vector<int> wt = getWrites(u);
 
        vector<int> gs, gt;
 
        for (int i = 1; i < (int)ws.size(); i++) {
            gs.push_back(ws[i] - ws[i - 1]);
        }
 
        for (int i = 1; i < (int)wt.size(); i++) {
            gt.push_back(wt[i] - wt[i - 1]);
        }
 
        sort(gs.begin(), gs.end());
        sort(gt.begin(), gt.end());
 
        vector<long long> ps(gs.size() + 1, 0);
        vector<long long> pt(gt.size() + 1, 0);
 
        for (int i = 0; i < (int)gs.size(); i++) {
            ps[i + 1] = ps[i] + gs[i];
        }
 
        for (int i = 0; i < (int)gt.size(); i++) {
            pt[i + 1] = pt[i] + gt[i];
        }
 
        vector<long long> a = getAns(s, m, wt, gt, pt);
        vector<long long> b = getAns(u, n, ws, gs, ps);
 
        for (int i = 0; i < (int)a.size(); i++) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '
';
 
        for (int i = 0; i < (int)b.size(); i++) {
            if (i) cout << ' ';
            cout << b[i];
        }
        cout << '
';
    }
 
    return 0;
}