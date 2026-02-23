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
  vector<int> b = a;
  sort(b.begin(), b.end());
  vector<int> c;
  for(int i=0;i<n;i++){
    if(a[i] != b[i]){
      c.push_back(a[i]);
    }
  }
  if(c.empty()) return cout << -1 << endl, void();
  int mn = b[0], mx = b.back();
  // sort(c.begin(), c.end());
  int ans = mx - mn;
  for(int x : c){
    ans = min(ans, max(abs(x - mn), abs(x - mx)));
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