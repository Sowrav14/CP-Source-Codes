#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

void solve() {

    int n; cin >> n;
    map<int, int> compress;
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }

    int coords = 0;
    for (auto &v : compress) {
        v.second = coords++;
    }

    vector<vector<pair<int, int>>> project(coords);
    for (int i = 0; i < n; i++) {
        project[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    }

    vector<long long> dp(coords, 0);
    for (int i = 0; i < coords; i++) {
        if (i > 0){
            dp[i] = dp[i - 1];
        }
        for (auto p : project[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
    cout << dp[coords - 1] << endl;
}

signed main() {
    Fast_IO()
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}