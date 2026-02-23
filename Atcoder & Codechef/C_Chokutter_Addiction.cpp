#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, t; cin >> n >> t;
  if(n == 0) return cout << t << endl, void();
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  if(a.back() != t) a.push_back(t);
  int ans = 0;
  int prev = 0;
  for(int i=0;i<a.size();i++){
    int cur = a[i];
    if(prev > cur) continue;
    // cout << i << " " << prev << " " << cur - prev << endl;
    ans += (cur - prev);
    prev = cur + 100;
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