#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    long long total;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        total = 0;
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);

        // remove old contributions
        total -= 1LL * sz[a] * sz[a];
        total -= 1LL * sz[b] * sz[b];

        parent[b] = a;
        sz[a] += sz[b];

        // add new contribution
        total += 1LL * sz[a] * sz[a];
    }

    void add_singletons(int n) {
        // initialize answer with each item as size 1 component
        total = n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n + 1), s(n + 1);
        vector<int> posp(n + 1), poss(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            posp[p[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            poss[s[i]] = i;
        }

        DSU dsu(n);
        dsu.add_singletons(n);

        auto try_unite = [&](int x, int y) {
            if (x < 1 || x > n || y < 1 || y > n) return;
            // Condition: x and y must be adjacent in BOTH permutations
            if (abs(posp[x] - posp[y]) == 1 && abs(poss[x] - poss[y]) == 1) {
                dsu.unite(x, y);
            }
        };

        // build initial edges
        for (int i = 1; i < n; i++) {
            try_unite(p[i], p[i + 1]);
            try_unite(s[i], s[i + 1]);
        }

        while (q--) {
            int tp, i, j;
            cin >> tp >> i >> j;
            if (tp == 1) {
                // swap in permutation p
                swap(p[i], p[j]);
                posp[p[i]] = i;
                posp[p[j]] = j;
            } else {
                // swap in permutation s
                swap(s[i], s[j]);
                poss[s[i]] = i;
                poss[s[j]] = j;
            }

            // after each swap, check adjacencies locally
            for (int k = -1; k <= 1; k++) {
                if (tp == 1) {
                    if (i + k >= 1 && i + k < n) try_unite(p[i + k], p[i + k + 1]);
                    if (j + k >= 1 && j + k < n) try_unite(p[j + k], p[j + k + 1]);
                } else {
                    if (i + k >= 1 && i + k < n) try_unite(s[i + k], s[i + k + 1]);
                    if (j + k >= 1 && j + k < n) try_unite(s[j + k], s[j + k + 1]);
                }
            }

            cout << dsu.total << "\n";
        }
    }
    return 0;
}
