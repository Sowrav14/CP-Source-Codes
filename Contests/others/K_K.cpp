#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
const int N = 1e5 + 9, MOD = 1e9 + 7;

int32_t main () {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n; cin >> n;
  vector <int> v (n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  auto vv = v;
  sort(vv.begin() + 1, vv.end());

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if(v[i] != vv[i]) cnt++;
    // if (i > 1 && vv[i] == vv[i - 1]) {
    //   cout << "Failed\n";
    //   return 0;
    // }
  }

  if (cnt <= 2) {
    cout << "Sorted\n";
  } else {
    cout << "Failed\n";
  }
  
  return 0;
} 