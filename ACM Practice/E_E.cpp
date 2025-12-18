#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, p, m; cin >> n >> p >> m;
  int x = (n - p);
  
  int mxr = 512;
  vector<vector<int>> dp(x+10, vector<int>(mxr+10, 0));
  dp[0][0] = 1;

  for(int s=1;s<=x;s++){
    for(int pl=0;pl+s<=x;pl++){
      for(int xr=0;xr<mxr;xr++){
        dp[s+pl][xr^s] = (dp[s+pl][xr^s] + dp[pl][xr]) % m;
      }
    }
  }

  cout << dp[x][p] % m << endl;

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