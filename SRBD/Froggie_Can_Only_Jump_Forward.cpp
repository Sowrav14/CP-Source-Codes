#include <bits/stdc++.h>
using namespace std;

// Iterative segment tree for range max on 1..n (1-based)
struct IterSegMax {
    int n;
    int sz;
    vector<int> seg;
    void init(int N) {
        n = N;
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, 0);
    }
    // arr is 1-based, size >= n+1
    void set_leaves(const vector<int>& arr) {
        for (int i = 0; i < sz; ++i) {
            if (i + 1 <= n) seg[sz + i] = arr[i + 1];
            else seg[sz + i] = 0;
        }
        for (int p = sz - 1; p >= 1; --p)
            seg[p] = max(seg[p << 1], seg[(p << 1) | 1]);
    }
    // inclusive query [L,R], returns 0 if L>R
    int query(int L, int R) const {
        if (L > R) return 0;
        int l = L + sz - 1, r = R + sz - 1;
        int res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, seg[l++]);
            if (!(r & 1)) res = max(res, seg[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N + 1);
        for (int i = 1; i <= N; ++i) cin >> A[i];

        // LOG: choose enough layers so 2^(LOG-1) > N
        int LOG = 1;
        while ((1LL << LOG) <= (long long)N) ++LOG;
        LOG += 1; // small margin

        // up[k][i] = furthest index reachable from i in <= 2^k jumps
        vector<vector<int>> up(LOG, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; ++i) up[0][i] = min(N, i + A[i]);

        // We'll keep a segment-tree per layer so queries max_{j in [L,R]} up[k][j] are O(log N)
        vector<IterSegMax> segs(LOG);
        segs[0].init(N);
        segs[0].set_leaves(up[0]);

        for (int k = 1; k < LOG; ++k) {
            // compute up[k] using segs[k-1]
            for (int i = 1; i <= N; ++i) {
                int L = i;
                int R = up[k - 1][i];
                if (L > R) up[k][i] = up[k - 1][i];
                else up[k][i] = segs[k - 1].query(L, R);
            }
            // build segment tree for this layer
            segs[k].init(N);
            segs[k].set_leaves(up[k]);
        }

        // answer queries: interval-expansion binary lifting
        while (Q--) {
            int s, d;
            cin >> s >> d;
            if (s >= d) { cout << 0 << '\n'; continue; }

            int L = s, R = s;
            int ans = 0;
            for (int k = LOG - 1; k >= 0; --k) {
                int newR = segs[k].query(L, R); // max_{j in [L,R]} up[k][j]
                if (newR < d) {
                    ans += (1 << k);
                    R = newR; // expand interval to the furthest we can reach with these extra 2^k jumps
                }
            }
            cout << ans + 1 << '\n';
        }
    }
    return 0;
}
