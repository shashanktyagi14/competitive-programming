#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#ifdef Doludu
template <typename T>
ostream& operator << (ostream &o, vector <T> vec) {
    o << "{"; int f = 0;
    for (T i : vec) o << (f++ ? " " : "") << i;
    return o << "}";
}
void bug__(int c, auto ...a) {
    cerr << "\e[1;" << c << "m";
    (..., (cerr << a << " "));
    cerr << "\e[0m" << endl;
}
#define bug_(c, x...) bug__(c, __LINE__, "[" + string(#x) + "]", x)
#define bug(x...) bug_(32, x)
#define bugv(x...) bug_(36, vector(x))
#define safe bug_(33, "safe")
#else
#define bug(x...) void(0)
#define bugv(x...) void(0)
#define safe void(0)
#endif
const int mod = 998244353, N = 1 << 20;
 
struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v) {
            return false;
        }
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};
 
// only works for integer coordinates!! maintain max
struct Line {
  mutable ll a, b, p;
  bool operator<(const Line &rhs) const { return a < rhs.a; }
  bool operator<(ll x) const { return p < x; }
};
struct DynamicHull : multiset<Line, less<>> {
  static const ll kInf = 1e18;
  ll Div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = kInf; return 0; }
    if (x->a == y->a) x->p = x->b > y->b ? kInf : -kInf;
    else x->p = Div(y->b - x->b, x->a - y->a);
    return x->p >= y->p;
  }
  void addline(ll a, ll b) { // ax + b
    auto z = insert({a, b, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  ll query(ll x) {
    auto l = *lower_bound(x);
    return l.a * x + l.b;
  }
};
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <array <int, 3>> arr;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        arr.pb({w, u, v});
    }
    sort(all(arr));
    Dsu dsu(n);
    vector <int> vec;
    ll base = 0;
    int cc = n;
    for (auto [w, u, v] : arr) {
        if (!dsu.Union(u, v)) {
            base += w;
        } else {
            cc--;
            vec.pb(w);
        }
    }
 
    reverse(all(vec));
 
    ll a = cc - 1, b = 0;
    DynamicHull hull;
    hull.addline(-a * (a + 1) / 2, 0);
    for (int i = 0; i < sz(vec); ++i) {
        a++, b += vec[i];
        hull.addline(-a * (a + 1) / 2, b);
        bug(a, b);
    }
 
    while (q--) {
        int x;
        cin >> x;
        cout << base + hull.query(x) << " 
"[q == 0];
    }
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}