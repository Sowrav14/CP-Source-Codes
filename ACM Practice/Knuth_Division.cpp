#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
using ll = long long;

/* Knuth optimization explanation:
We solve interval DP where:
res[l][r] = min over l < m < r ( res[l][m] + res[m][r] ) + cost(l,r)
cost(l,r) = sum of x[l..r-1] = pref[r] - pref[l]

Knuth optimization applies because:
mid[l][r-1] <= mid[l][r] <= mid[l+1][r]

We use:
mid[l][r] = argmin of res[l][m] + res[m][r]
Transitions only check m in [mid[l][r-1], mid[l+1][r]].
This reduces complexity to O(n^2). */

int n;
ll pref[N];
ll res[N][N];
int mid[N][N];

ll solve_knuth(int k) {
    for (int s = 0; s <= k; s++) {
        for (int l = 0; l + s <= k; l++) {
            int r = l + s;
            if (s < 2) {
                res[l][r] = 0;
                mid[l][r] = l;
                continue;
            }
            int mleft = mid[l][r-1];
            int mright = mid[l+1][r];
            if (mright < mleft) swap(mleft, mright);

            res[l][r] = (ll)2e18;

            for (int m = mleft; m <= mright; m++) {
                ll tmp = res[l][m] + res[m][r] + (pref[r] - pref[l]);
                if (tmp < res[l][r]) {
                    res[l][r] = tmp;
                    mid[l][r] = m;
                }
            }
        }
    }
    return res[0][k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    pref[0] = 0;
    for (int i=1;i<=n;i++){
        ll x; cin >> x;
        pref[i] = pref[i-1] + x;
    }

    // DP runs on interval [0..n]
    cout << solve_knuth(n) << "\n";
    return 0;
}
