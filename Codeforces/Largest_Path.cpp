#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, sz;
    vector<long long> compOR;

    DSU(int n=0) { init(n); }

    void init(int n_) {
        n = n_;
        p.resize(n+1);
        sz.assign(n+1, 1);
        compOR.assign(n+1, 0);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    void addEdge(int u, int v, long long w) {
        int a = find(u), b = find(v);
        if (a == b) {
            compOR[a] |= w;
            return;
        }
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        compOR[a] |= compOR[b];
        compOR[a] |= w;
    }

    long long query(int u, int v) {
        int a = find(u), b = find(v);
        if (a != b) return -1;
        return compOR[a];
    }
};

struct Edge {
    int u, v;
    long long w;
};

struct Query {
    int type;
    int x, y; // for type1: x=edgeIndex; for type2: x=u, y=v
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m+1);
        for (int i = 1; i <= m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        int q;
        cin >> q;
        vector<Query> qs(q);
        vector<char> willDelete(m+1, 0);

        for (int i = 0; i < q; i++) {
            int tp;
            cin >> tp;
            qs[i].type = tp;
            if (tp == 1) {
                int idx; cin >> idx;
                qs[i].x = idx;
                qs[i].y = 0;
                willDelete[idx] = 1;
            } else {
                int u, v; cin >> u >> v;
                qs[i].x = u;
                qs[i].y = v;
            }
        }

        DSU dsu(n);

        // Start from the final graph: add edges that are never deleted
        for (int i = 1; i <= m; i++) {
            if (!willDelete[i]) {
                dsu.addEdge(edges[i].u, edges[i].v, edges[i].w);
            }
        }

        vector<long long> answers;
        answers.reserve(q);

        // Process queries in reverse
        for (int i = q - 1; i >= 0; i--) {
            if (qs[i].type == 2) {
                answers.push_back(dsu.query(qs[i].x, qs[i].y));
            } else {
                int idx = qs[i].x; // add back this edge
                dsu.addEdge(edges[idx].u, edges[idx].v, edges[idx].w);
            }
        }

        // Reverse answers back to original order
        for (int i = (int)answers.size() - 1; i >= 0; i--) {
            cout << answers[i] << "\n";
        }
    }
    return 0;
}