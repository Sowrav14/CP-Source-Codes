#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int n; cin >> n;
    int px, py, qx, qy; cin >> px >> py >> qx >> qy;
    vector<int> v(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tot += v[i];
    }

    int dx = qx - px, dy = qy - py;
    double ddis = sqrtl(dx * dx + dy * dy);

    if (n == 1) {
        if (abs(v[0] - ddis) < 1e-9) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if (tot >= ddis && (int)(tot - ddis + 1e-9) % 2 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

signed main() {
    Fast_IO();
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}