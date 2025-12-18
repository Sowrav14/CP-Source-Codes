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
  vector<int> a(4, 0);
  for(int i=0;i<n;i++){
    int x; cin >> x;
    a[x]++;
  }
  int ans = 0;
  ans += min(a[1], a[3]);
  ans += max(0ll, a[2] - 1);

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