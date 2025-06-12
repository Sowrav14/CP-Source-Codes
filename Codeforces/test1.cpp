#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

map<tuple<int, bool, int, bool>, int> dp;

struct Digitdp {
 int n, k;
 vector<int> num;

 Digitdp(int a, int k) {
  n = a;
  this->k = k;
  while (a > 0) {
   num.push_back(a % 10);
   a /= 10;
  }
  reverse(num.begin(), num.end());
 }

 int recur(int i, bool tight, int dprod, bool started) {
  if (i == num.size()) {
   return dprod > k ? 0 : 1;
  }
  auto key = make_tuple(i, tight, dprod, started);
  if (dp.find(key) != dp.end()) return dp[key];

  int limit = tight ? 9 : num[i];
  int ans = 0;
  for (int d = 0; d <= limit; d++) {
   bool new_tight = tight || (d < num[i]);
   bool new_started = started || (d != 0);
   int new_prod = new_started ? dprod * d : 1;
   ans += recur(i + 1, new_tight, new_prod, new_started);
  }

  return dp[key] = ans;
 }

 int query() {
  return recur(0, 0, 1, 0);
 }
};

void solve() {
 int a, k;
 cin >> a >> k;
 dp.clear();
 Digitdp obj(a, k);
 cout << obj.query()-1 << endl;
}

signed main() {
 Fast_IO();
 int t = 1;
 // cin >> t;
 for (int i = 1; i <= t; i++) {
  cout << "Case " << i << ": ";
  solve();
 }
}
