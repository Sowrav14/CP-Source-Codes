#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 3000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
string s;
int dp[N][N];

int edit_pal(int i, int j){
  if(i >= j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  if(s[i] == s[j]) return edit_pal(i+1, j-1);
  int ans = inf;
  ans = min(ans, 1 + edit_pal(i+1, j));
  ans = min(ans, 1 + edit_pal(i, j-1));
  ans = min(ans, 1 + edit_pal(i+1, j-1));
  return dp[i][j] = ans;
}

void solve(){

    cin >> s;
    n = s.size();
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        dp[i][j] = -1;
      }
    }
    cout << edit_pal(0, n-1) << endl;

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