#include<bits/stdc++.h>
using namespace std;

#define int long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

struct CHT {
  vector<int> m, b;
  int ptr = 0;

  bool bad(int l1, int l2, int l3) {
    return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2])  <= 1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]); //(slope dec+query min),(slope inc+query max)
    // return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2])  >= 1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]); //(slope dec+query max), (slope inc+query min)
  }

  void add(int _m, int _b) {
    m.push_back(_m);
    b.push_back(_b);
    int s = m.size();
    while(s >= 3 && bad(s - 3, s - 2, s - 1)) {
      s--;
      m.erase(m.end() - 2);
      b.erase(b.end() - 2);
    }
  }

  int f(int i, int x) {
    return m[i] * x + b[i];
  }

  //(slope dec+query min), (slope inc+query max) -> x increasing
  //(slope dec+query max), (slope inc+query min) -> x decreasing
  int query(int x) {
    if(ptr >= m.size()) ptr = m.size() - 1;
    while(ptr < m.size() - 1 && f(ptr + 1, x) < f(ptr, x)) ptr++;
    return f(ptr, x);
  }

  int bs(int l, int r, int x) {
    int mid = (l + r) / 2;
    if(mid + 1 < m.size() && f(mid + 1, x) < f(mid, x)) return bs(mid + 1, r, x); // > for max
    if(mid - 1 >= 0 && f(mid - 1, x) < f(mid, x)) return bs(l, mid - 1, x); // > for max
    return f(mid, x);
  }
} cht;

int h[N], dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;
  for(int i = 1; i <= n; i++) cin >> h[i];
  dp[1] = 0;
  cht.add(-2*h[1], h[1]*h[1]+dp[1]);
  for(int i = 2; i <= n; i++) {
    dp[i] = cht.bs(0, cht.m.size()-1, h[i]) + h[i]*h[i] + c;
    cht.add(-2*h[i], h[i]*h[i]+dp[i]);
  }
  cout << dp[n] << endl;
  return 0;
}