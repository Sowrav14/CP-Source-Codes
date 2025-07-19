#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // dp[c] stores max sum achievable with c coins
    vector<int> dp(2 * n + 1, LLONG_MIN);
    dp[0] = 0; // Base case: 0 coins, 0 sum
    
    // Track current x (number of selections)
    int x = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> new_dp(2 * n + 1, LLONG_MIN);
        for (int c = 0; c <= 2 * n; ++c) {
            if (dp[c] == LLONG_MIN) continue; // Skip unreachable states
            // Option 1: Do nothing (cost 0 coins)
            new_dp[c] = max(new_dp[c], dp[c]);
            // Option 2: Pay 1 coin, add a[i]
            if (c + 1 <= 2 * n) {
                new_dp[c + 1] = max(new_dp[c + 1], dp[c] + a[i]);
            }
            // Option 3: Pay 2 coins, add a[i] + x
            if (c + 2 <= 2 * n) {
                new_dp[c + 2] = max(new_dp[c + 2], dp[c] + a[i] + x);
            }
        }
        dp = new_dp;
        x++; // Increment x for the next iteration (as if we selected an element)
    }
    
    // Output maximum sum for each K from 1 to 2N
    for (int k = 1; k <= 2 * n; ++k) {
        cout << (dp[k] == LLONG_MIN ? 0 : dp[k]) << " ";
    }
    cout << '\n';
}

signed main() {
    Fast_IO()
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}