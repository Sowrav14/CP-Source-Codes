#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  int ans = 1;
  vector<int> d(n+1, 0);
  int cnt = 1;
  if(a[0] <= n) d[a[0]]--;
  for(int i=1;i<n;i++){
    // cout << i << " " << cnt << " " << d[i] << endl;
    cnt += d[i];
    if(cnt > 0) ans++;
    else break;
    int x = i + a[i];
    cnt++;
    if(x <= n) d[x]--;
  }
  cout << ans << endl;

}


signed main(){
  Fast_IO()
  int t = 1;
  // cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}