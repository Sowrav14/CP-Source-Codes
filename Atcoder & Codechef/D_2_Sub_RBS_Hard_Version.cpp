#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int n;
string s;

int dp[101][101][101][3][3];

int recur(int i, int o, int c, int f, int p){

  if(i == n){
    if(o == c and f == 2){
      return o + c - 2;
    } else {
      return 0;
    }
  }
  if(dp[i][o][c][f][p] != -1){
    return dp[i][o][c][f][p];
  }

  int res = 0;

  res = (res%M + recur(i+1, o, c, f, p))%M;

  if(s[i] == '(') {
    if(f == 0){
      if(p == 1){
        res = (res%M + recur(i+1, o+1, c, 1, 0)%M)%M;
      } else {
        res = (res%M + recur(i+1, o+1, c, f, 0)%M)%M;
      }
    } else if(f == 1){
      res = (res%M + recur(i+1, o+1, c, 2, 0)%M)%M;
    } else {
      res = (res%M + recur(i+1, o+1, c, f, 0)%M)%M;
    }
  } else {
    if(o >= c+1){
      res = (res%M + recur(i+1, o, c+1, f, 1)%M)%M;
    }
  }

  return dp[i][o][c][f][p] = res % M;
}


void solve(){

  cin >> n;
  cin >> s;
  memset(dp, -1, sizeof(dp));
  int ans = recur(0, 0, 0, 0, 0);
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