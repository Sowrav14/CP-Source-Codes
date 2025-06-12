// #include <bits/allocator.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        vector a(n, 0ll);
        for (auto &y : a) cin >> y;
        vector b(n, 0);
        for (auto &y : b) cin >> y;
        
        const ll inf = 1e18;
        vector pre(n, -inf), suf(n, -inf);
        vector mxl(n, -inf), mxr(n, -inf);
        for (int i = 0; i < n; ++i) {
            if (i) pre[i] = pre[i-1], mxl[i] = mxl[i-1];
            if (pre[i] < 0) pre[i] = max(pre[i], a[i]);
            else pre[i] += max(0ll, a[i]);
            if (b[i] == 1) mxl[i] = max(mxl[i], a[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            if (i < n-1) suf[i] = suf[i+1], mxr[i] = mxr[i+1];
            if (suf[i] < 0) suf[i] = max(suf[i], a[i]);
            else suf[i] += max(0ll, a[i]);
            if (b[i] == 1) mxr[i] = max(mxr[i], a[i]);
        }

        ll ans = inf;
        for (int i = 1; i+1 < n; ++i) {
            ll lt = pre[i-1], rt = suf[i+1];
            if (lt + rt >= x) {
                ans = 0;
                break;
            }
            // Increase on left
            if (mxl[i-1] > -inf) {
                ans = min(ans, x - rt - max(0ll, lt) - min(0ll, mxl[i-1]));
            }
            // Increase on right
            if (mxr[i+1] > -inf) {
                ans = min(ans, x - lt - max(0ll, rt) - min(0ll, mxr[i+1]));
            }
        }
        cout << ans << '\n';
    }
}