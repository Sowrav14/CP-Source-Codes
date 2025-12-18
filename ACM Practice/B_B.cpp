#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
// #define endl "\n"
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

void solve(){

  int n; cin >> n;

  int k; cin >> k;
  int mx = k;
  function<void(int, int, int)> check = [&](int l, int r, int kk) -> void {
    if(kk < mx or r > n) return;
    check(l, r+1, kk);

    cout << l << " " << r << endl;
    cin >> k;
    if(k < mx){
      cout << l << " " << r << endl;
      cin >> k;
      mx = max(mx, k);
    } else if(k == mx) {
      check(l, r+1, k);
    } else {
      mx = max(mx, k);
    }
  };

  for(int i=1;i<=n && mx < n;i++) check(i, i, mx);

}

signed main() {
//  Fast_IO()
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++){
    // cout << "Case #" << i << ": ";
    solve();
  }
}
