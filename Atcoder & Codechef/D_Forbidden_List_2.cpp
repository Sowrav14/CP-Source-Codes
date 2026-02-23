#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 4e18;


void solve(){
  int n, q; cin >> n >> q;

  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(), a.end());

  while(q--){
    int x, y;
    cin >> x >> y;

    int l = x, r = x + y + n + 5, ans = -1;
    while(l <= r){
      int mid = (l + r) / 2;
      int cnt = upper_bound(a.begin(), a.end(), mid) - lower_bound(a.begin(), a.end(), x);
      int missing = (mid - x + 1) - cnt;
      if(missing >= y){
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
}

signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
