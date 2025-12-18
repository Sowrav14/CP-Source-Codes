#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, k; cin >> n >> k;
  if(k == 1){
    cout << 0 << endl;
    return;
  }

  vector<vector<pair<int,int>>> pos(k + 1, vector<pair<int,int>>());
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        int x; cin >> x;
        pos[x].push_back({i, j});
    }
  }

  int ans = inf;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
  for(auto &p : pos[k]){
    dp[p.first][p.second] = 0;
  }

  for(int i=k-1;i>=1;i--){
    for(auto &p : pos[i]){
        int mn = inf;
        for(auto &q : pos[i+1]){
            int dist = abs(p.first - q.first) + abs(p.second - q.second);
            mn = min(mn, dp[q.first][q.second] + dist);
        }
        dp[p.first][p.second] = mn;
        if(i == 1){
            ans = min(ans, dp[p.first][p.second]);
        }
    }
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