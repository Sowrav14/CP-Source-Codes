#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = (ll)-9e18;
const ll UNVIS = (ll)9e18;

int n, t;
int L, U;
vector<vector<ll>> v;
vector<vector<ll>> pref;
vector<ll> mem;

ll dp(int tt) {
  if (tt > t) return 0;             // finished successfully
  if (mem[tt] != UNVIS) return mem[tt];

  ll best = NEG_INF;
  // choose sensor s and a length len in [L, U] such that segment is within [tt, t]
  int max_j = min(t, tt + U - 1);
  for (int s = 1; s <= n; ++s) {
    for (int j = tt + L - 1; j <= max_j; ++j) {
      if (j > t) break;
      // sum v[s][tt..j] = pref[s][j] - pref[s][tt-1]
      ll segsum = pref[s][j] - pref[s][tt - 1];
      ll rec = dp(j + 1);
      best = max(best, rec + segsum);
    }
  }

  mem[tt] = best;
  return best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  if (!(cin >> n >> t)) return 0;
  v.assign(n + 1, vector<ll>(t + 1, 0));
  pref.assign(n + 1, vector<ll>(t + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= t; ++j) {
      cin >> v[i][j];
      pref[i][j] = pref[i][j - 1] + v[i][j];
    }
  }

  cin >> L >> U;

  mem.assign(t + 2, UNVIS);
  ll ans = dp(1);
  if (ans <= 0) cout << -1 << '\n';
  else cout << ans << '\n';

  return 0;
}