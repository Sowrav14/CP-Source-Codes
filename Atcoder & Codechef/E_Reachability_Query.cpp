#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// Disjoint Set Union
struct DSU {
    vector<int> par, rnk, sz, colored_count;
    int c, mx = 1;

    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), colored_count(n + 1, 0), c(n) {
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }

    int find(int i) {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int get_size(int i) {
        return sz[find(i)];
    }

    pair<int, int> cc_count() {
        return {c, mx};
    }

    bool has_colored(int i) {
        return colored_count[find(i)] > 0;
    }

    void toggle_color(int v, int color) {
        int root = find(v);
        colored_count[root] += (color == 1 ? 1 : -1);
    }

    int merge(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return -1;
        --c;
        if (rnk[pi] > rnk[pj]) swap(pi, pj);
        par[pi] = pj;
        sz[pj] += sz[pi];
        mx = max(mx, sz[pj]);
        if (rnk[pi] == rnk[pj]) rnk[pj]++;
        colored_count[pj] += colored_count[pi];
        colored_count[pi] = 0;
        return pj;
    }
};

void solve() {
    int n, q; 
    cin >> n >> q;
    vector<int> c(n + 1, 0);
    DSU dsu = DSU(n);
    
    while (q--) {
        int t;  cin >> t;
        if (t == 1) {
            int u, v;  cin >> u >> v;
            dsu.merge(u, v);
        } else if (t == 2) {
            int v;  cin >> v;
            c[v] = 1 - c[v];
            dsu.toggle_color(v, c[v]);
        } else if (t == 3) {
            int v;  cin >> v;
            cout << (dsu.has_colored(v) ? "Yes" : "No") << "\n";
        }
    }
}

signed main() {
    Fast_IO()
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}