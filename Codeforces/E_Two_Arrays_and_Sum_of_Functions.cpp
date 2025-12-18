#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 998244353;
const int inf = 1e12;


void solve(){

  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];

  for(int i=0;i<n;i++){
    int x = (i + 1) * (n - i);
    a[i] *= x;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  int ans = 0;
  for(int i=0;i<n;i++){
    ans = (ans + (a[i] % M * b[i] % M) % M) % M;
  }
  cout << ans % M << endl;

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