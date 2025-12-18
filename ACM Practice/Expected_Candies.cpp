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
  vector<vector<vector<double>>> dp(
    n,
    vector<vector<double>>(
      n,
      vector<double>(2, -1.0)
    )
  );
  function<double(int, int, bool)> recur = [&](int i, int j, bool f) -> double {
    if(i > j) return 0.0;
    if(i == j) return (double)a[i] * (double)(!f);
    if(dp[i][j][f] != -1.0) return dp[i][j][f];
    double res = 0.0;
    if(f){  
      res += (double)(recur(i + 1, j, !f)) / 2.0;
      res += (double)(recur(i, j - 1, !f)) / 2.0;
    } else {
      res += (double)(a[i] + recur(i + 1, j, !f)) / 2.0;
      res += (double)(a[j] + recur(i, j - 1, !f)) / 2.0;
    }
    return dp[i][j][f] = res;
  };

  double ans = recur(0, n - 1, 0);
  cout << fixed << setprecision(15) << ans << endl;

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