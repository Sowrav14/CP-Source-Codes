#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 100 + 10;
const int M = 1000 + 10;
const int inf = 1e12;

int n;
int a[N], b[N];
int dp[N][M];

int recur(int i, int c){
  if(i == n) return 0;
  if(dp[i][c] != -1) return dp[i][c];
  int ans = 0;
  ans = max(ans, recur(i+1, c));
  if(b[i] <= c) ans = max(ans, recur(i+1, c - b[i]) + a[i]);
  return dp[i][c] = ans;
}

void solve(){

  int c; cin >> c;
  vector<int> v;
  int x; 
  while(cin >> x){
    v.push_back(x);
  }
  n = v.size() / 2;
  for(int i=0;i<n;i++){
    a[i] = v[i];
    b[i] = v[i+n];
  }
  memset(dp, -1, sizeof(dp));
  cout << recur(0, c) << endl;

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