#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int get(int n, int k){
  int l = 0, r = n;
  int ret = 0;
  while(l <= r){
    int m = (l + r) / 2;
    int x = m * (m + 1) / 2;
    if(x <= k){
      l = m + 1;
      ret = m;
    } else {
      r = m - 1;
    }
  }
  return ret;
}

void solve(){

  int n, m, k; cin >> n >> m >> k;
  int ans = 1;
  for(int i=k;i>=1;i--){
    int w = k - i;
    int left = m - w;
    if(left < w) break;
    int r = get(n, left);
    r = min(r, n - k);
    // cout << "i: " << i << " r: " << r << " w: " << w << endl;
    ans = max(ans, r + w + 1);
  }

  for(int i=k;i<=n;i++){
    int w = i - k;
    int left = m - w;
    if(left < w) break;
    int l = get(n, left);
    l = min(l, k - 1);
    // cout << "i: " << i << " l: " << l << " w: " << w << endl;
    ans = max(ans, l + w + 1);
  }
  cout << ans << endl;

}


signed main(){
  Fast_IO()
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}