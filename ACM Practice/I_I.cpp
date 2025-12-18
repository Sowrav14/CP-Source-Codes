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
  vector<string> a(n+10);
  for(int i=1;i<=n;i++){
    string s; cin >> s;
    string ss = "";
    for(int j=0;j<min(3ll, (int)s.size());j++){
      ss += s[j];
    }
    a[i] = ss;
  }
  vector<vector<int>> dp(n+10, vector<int>(4, inf));
  dp[0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<3;j++){
      int cnt = j;
      for(int k=0;k<a[i].size();k++){
        if(a[i][k] == 'A' || a[i][k] == 'E' || a[i][k] == 'I' || a[i][k] == 'O' || a[i][k] == 'U' || a[i][k] == 'Y'){
          cnt = 0;
        } else {
          cnt++;
        }
        if(cnt > 2) break;
        dp[i][cnt] = min(dp[i][cnt], dp[i-1][j] + k + 1);
      }
    }
  }

  int ans = dp[0][1];
  for(int i=0;i<3;i++){
    ans = min(ans, dp[n][i]);
  }

  if(ans >= inf){
    cout << "*" << endl;
  } else {
    cout << ans << endl;
  }

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