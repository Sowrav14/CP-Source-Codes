#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int T, L, t; cin >> T >> L >> t;
  int l = 0, r = 1e9;
  int ans = 0;
  while(l <= r){
    int m = (l + r) / 2;
    double tt = ((1.0 * m * m) / (T * T * L)) + m;
    int tim = tt;
    if(tt <= t){
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
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