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
  vector<int> a(n+1), pre(n+1), r(n+2), sr(n+3);

  for(int i=1;i<=n;i++){
      cin >> a[i];
      pre[i] = pre[i-1] + a[i];
  }
  int sum = pre[n];
  for(int i=1;i<=n;i++){
      r[i] = i*i + i - pre[i];
  }

  sr[n] = r[n];
  for(int i=n-1;i>=1;i--){
    sr[i] = max(sr[i+1], r[i]);
  }

  int cng = 0; 
  for(int i=1;i<=n;i++){
    int prev = -i*i + i + pre[i-1];
    cng = max(cng, sr[i] + prev);
  }
  cout << sum + cng << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
