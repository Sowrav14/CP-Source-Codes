#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int mw = 50000;
const int inf = 1e18;
const int LOG = 17; // log2(50000) approx 16

int dp[mw + 1];
int st[LOG][mw + 1];

void solve() {
    int n, q; 
    cin >> n >> q;
    vector<int> wt(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++) cin >> wt[i] >> val[i];

    // Reset DP for each test case
    for (int i = 0; i <= mw; i++) dp[i] = -inf;
    dp[0] = 0;

    int current_max_w = 0;
    for (int i = 1; i <= n; i++) { // FIXED: Start from 1
        if (wt[i] > mw) continue;
        for (int w = mw; w >= wt[i]; w--) {
            if (dp[w - wt[i]] != -inf) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
    }

    // Build Sparse Table on the same memory
    for (int i = 0; i <= mw; i++) st[0][i] = dp[i];
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 <= mw; i++) {
            st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        if (l > mw) {
            cout << -1 << "\n";
            continue;
        }
        r = min(r, (int)mw);
        int k = __lg(r - l + 1);
        int ans = max(st[k][l], st[k][r - (1 << k) + 1]);
        if (ans < 0) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}

signed main() {
    Fast_IO();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}