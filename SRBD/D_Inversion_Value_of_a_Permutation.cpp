#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios::sync_with_stdio(false); cin.tie(nullptr)

int C2(int x) {
    return x * (x - 1) / 2;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int T = n * (n - 1) / 2;
    if (k > T) {
        cout << 0 << "\n";
        return;
    }
    int S = T - k;  // we must make sum of C2(L_i) = S
    int rem = n;
    int S_rem = S;
    vector<int> blocks;
    while (rem > 0) {
        bool found = false;
        for (int L = rem; L >= 1; L--) {
            if (C2(L) <= S_rem) {
                blocks.push_back(L);
                rem -= L;
                S_rem -= C2(L);
                found = true;
                break;
            }
        }
        if (!found) {
            // should not happen under correct bounds
            cout << 0 << "\n";
            return;
        }
    }
    if (S_rem != 0) {
        cout << 0 << "\n";
        return;
    }
    // assign actual numbers
    vector<int> ans;
    int cur = n;
    for (int L : blocks) {
        int start = cur - L + 1;
        for (int x = start; x <= cur; x++) {
            ans.push_back(x);
        }
        cur -= L;
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main(){
    Fast_IO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
