#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int x;
    cin >> x;
    int c = 4 * x - 1;

    if (c == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> ans;
    int abs_c = abs(c);

    for (int d = -1; d * d <= abs_c; d += 2) {
        if (c % d != 0) continue;
        ans.push_back((d - c / d - 2) / 4);
        ans.push_back((-d - c / (-d) - 2) / 4);
        int cd = c / d;
        ans.push_back((cd - c / cd - 2) / 4);
        ans.push_back((-cd - c / (-cd) - 2) / 4);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << "\n";
    for (int n : ans) {
        cout << n << " ";
    }
    cout << "\n";
}

signed main() {
    Fast_IO()
    solve();
}