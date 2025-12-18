#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e7 + 10; 

int a[N];

void solve() {
  int n; cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = n; i < N; i++) {
    a[i] = sum / n;
    sum -= a[i - n];
  }
  int q; cin >>  q;
  while(q--) {
    int x; cin >> x;
    x--;
    if(x < N) cout << a[x] << "\n";
    else cout << a[N - 1] << '\n';
  }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
}