#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 10;
const double EPS = 1e-6;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    double l = 0, r = 1e15, ans = 0;
    for (int iter = 0; iter < 100; iter++) {
        double lesum = (l + r) / 2;
        vector<double> dp(n + 2, 0);
        dp[n + 1] = 0;
        
        for (int i = n; i >= 1; i--) {
            double x = a[i] + dp[i + 1];
            double y = b[i] + lesum / (n + 1);
            dp[i] = min(x, y);
        }
        
        double acsum = 0;
        for (int x = 1; x <= n + 1; x++) acsum += dp[x];
        
        if (abs(acsum - lesum) < EPS) {
            ans = dp[1];
            break;
        } else if (acsum > lesum) {
            l = lesum;
        } else {
            r = lesum;
        }
    }
    
    cout << fixed << setprecision(10) << ans << endl;
}

signed main() {
    Fast_IO()
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}