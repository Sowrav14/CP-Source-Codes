#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 1e5 + 9, MOD = 1e9 + 7;

vector<int> divs;
void FINDING_DIVISORS(int n) {
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) divs.push_back(n / i);
    }
  }
  //--SORT KORA OPTIONAL--//
  sort(divs.begin(), divs.end());
  // for (auto x: divs) cout << x << ' ';
}

int32_t main () {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int y, k; cin >> y >> k;
  FINDING_DIVISORS(y);
  int x = 1;
  // k;
  while (k) {
    int gcd = __gcd(x, y);
    int num = -1;
    for (auto d: divs) {
      if (gcd != d && d % gcd == 0) {
        num = d;
        break;
      }
    }
    if (num == -1) {
      x += k * gcd;
      k = 0;
    } else {
      // cout << "YO" << '\n';
      int cost = num / gcd - 1;
      cout << "\nYO " << x << ' ' << gcd << ' ' << num << ' ' << cost << ' ' << k << '\n';
      if (cost <= k) {
        k -= cost;
        x += cost * gcd;
      } else {
        x += gcd * k;
        k = 0;
      }
    }
  }
  cout << x << '\n';
  
  return 0;
} 