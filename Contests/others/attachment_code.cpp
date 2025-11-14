#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
int mid;

int inside = 0, cnt = 0;
int u1, v1, u2, v2;
int mps[505][505];
bool vis[505][505];
int R[250005], C[250005];

void dfs(int r, int c) {
    if (r <= 0 || r > n || c <= 0 || c > m) return;
    if (vis[r][c]) return;
    vis[r][c] = true;
    if (mps[r][c] > mid) return;
    if (mps[r][c] == 0) {
        if (not (u1 <= r && r <= u2 && v1 <= c && c <= v2)) cnt++;
    }

    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);
}

void solve() {
    cin >> n >> m >> k;

    // clear arrays
    memset(mps, 0, sizeof(mps));
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));

    for (int i = 1; i <= k; i++) {
        cin >> R[i] >> C[i];
        mps[R[i]][C[i]] = i;
    }

    cin >> u1 >> v1 >> u2 >> v2;

    int lo = 0, hi = k, ans = k + 1;
    inside = 0;
    for (int i = 1; i <= k; i++) {
        if (u1 <= R[i] && R[i] <= u2 && v1 <= C[i] && C[i] <= v2) {
            lo = max(lo, i);
            inside++;
        }
    }

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        cnt = 0;
        memset(vis, false, sizeof(vis));
        dfs(u1, v1);
        if (cnt >= inside) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (ans == k + 1) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
