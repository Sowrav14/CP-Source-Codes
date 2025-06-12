#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 2) {
        int y = (2 * a[0] - a[1]) / 3;
        if ((2 * a[0] - a[1]) % 3 == 0 && y >= 0 && y + (a[1] - a[0]) >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    int d = a[1] - a[0];
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] != d) {
            cout << "NO\n";
            return;
        }
    }
    int num = 2 * a[0] - a[1];
    int dnum = n + 1;
    if (num % dnum == 0 && num / dnum >= 0) {
        int y = num / dnum;
        int x = y + d;
        if (x >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
}

signed main() {
    Fast_IO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}