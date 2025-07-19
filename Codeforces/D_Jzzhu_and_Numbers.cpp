#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
const int MAX_MASK = 1 << 20;

int a[N], f[MAX_MASK], p2[MAX_MASK];

void solve() {
    int n; cin >> n;

    p2[0] = 1;
    for (int i = 1; i < MAX_MASK; i++){
        p2[i] = (p2[i - 1] << 1) % M;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < MAX_MASK; j++){
            if (((j >> i) & 1) == 0) {
                f[j] += f[j | (1 << i)];
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < MAX_MASK; j++){
        (ans += ((__builtin_popcount(j) & 1) ? -1 : 1) * (p2[f[j]] - 1)) %= M;
    }
    cout << (ans + M) % M << "\n";
}

signed main() {
    Fast_IO();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}