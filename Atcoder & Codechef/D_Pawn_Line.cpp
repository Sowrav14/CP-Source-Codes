#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){
  int n; cin >> n;
  vector<int> a(n+1), left(n+1), right(n+2);
  for(int i=1;i<=n;i++) cin >> a[i];

  left[1] = a[1];
  for(int i=2;i<=n;i++){
    left[i] = min(a[i], left[i-1] + 1);
  }

  right[n] = a[n];
  for(int i=n-1;i>=1;i--){
    right[i] = min(a[i], right[i+1] + 1);
  }

  int ans = 0;
  for(int i=1;i<=n;i++){
    int mn = min(left[i], right[i]);
    ans += (a[i] - mn);
  }

  cout << ans << endl;
}

signed main(){
  Fast_IO()
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
    solve();
  }
}
