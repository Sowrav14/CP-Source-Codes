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

  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=1;j<a[i];j++){
      if((i-a[i]*j) < 0 and (i + a[i]*j >= n)) break;
      if((i-a[i]*j) >= 0 and a[i-a[i]*j] == j) ans++;
      if((i + a[i]*j < n) and a[i + a[i]*j] == j) ans++;
    }
    if(i-a[i]*a[i]>=0 && a[i-a[i]*a[i]]==a[i]) ans++;
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