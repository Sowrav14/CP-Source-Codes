#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, h, t; cin >> n >> h >> t;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  int sum = 0;
  for(int i=0;i<n;i++){
    sum += a[i];
  }
  int x = h / sum;
  h -= x * sum;
  int tim = x * n + (x - (h == 0)) * t;
  if(h == 0){
    cout << tim << endl;
    return;
  }

  vector<int> sufmx(n);
  sufmx[n-1] = a[n-1];
  for(int i=n-2;i>=0;i--){
    sufmx[i] = max(sufmx[i+1], a[i]);
  }
  sum = 0;
  int mn = inf;
  for(int i=0;i<n-1;i++){
    sum += a[i];
    mn = min(mn, a[i]);
    if(mn < sufmx[i+1]) {
      if(sum - mn + sufmx[i+1] >= h){
        cout << tim + i + 1 << endl;
        return;
      }
    }
    if(sum >= h){
      cout << tim + i + 1 << endl;
      return;
    }
  }
  cout << tim + n << endl;

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