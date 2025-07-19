

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
#define pb push_back
#define fi first
#define se second
typedef int64_t ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vec<int> a(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        vec<int> freq(mx+1);
        for (int v : a) freq[v]++;
        ll ans = 0;
        int C = mx;
        for (int x = 1; x <= C; ++x) {
            if (!freq[x]) continue;
            int lo = x+1, hi = C, bestY = x;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                bool ok = false;
                int s = 0, min_pref = 0, last_zero_mp = 1e9;
                bool in_seg = false, has_zero = false;
                for (int i = 0; i < n && !ok; ++i) {
                    if (a[i] < x) {
                        in_seg = false;
                    } else {
                        if (!in_seg) {
                            in_seg = true;
                            s = 0;
                            min_pref = 0;
                            last_zero_mp = INT_MAX;
                            has_zero = false;
                        }
                        if (a[i] == x) {
                            has_zero = true;
                            last_zero_mp = min(last_zero_mp, min_pref);
                        }
                        s += (a[i] >= mid ? 1 : -1);
                        min_pref = min(min_pref, s);
                        if (has_zero && s - last_zero_mp >= 0) {
                            ok = true;
                        }
                    }
                }
                if (ok) {
                    bestY = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans = max(ans, (ll)(bestY - x));
        }
        cout << ans << endl;
    }
    return 0;
}