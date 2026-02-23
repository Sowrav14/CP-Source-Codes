#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1500 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n; 
string s, t;
int dp[N][30][30][2][2];

// f means if the current is already greater than s[i] or not
// g means if the current is already less than t[i] or not
int ddp(int i, int p1, int p2, bool f, bool g){
  if(i == n) return 1;
  if(dp[i][p1][p2][f][g] != -1) return dp[i][p1][p2][f][g];

  int ans = 0;
  int st = f ? 'a' : s[i];
  int et = g ? 'z' : t[i];

  for(int c = st; c <= et; c++){
    if(i > 1 and c - 'a' == p1) continue;
    int np1 = p2;
    int np2 = c - 'a';
    bool nf = f || (c > s[i]);
    bool ng = g || (c < t[i]);
    ans += ddp(i + 1, np1, np2, nf, ng);
    ans %= M;
  }
  ans %= M;
  return dp[i][p1][p2][f][g] = ans;
}


void solve(){

  cin >> n;
  cin >> s >> t;
  // memset(dp, -1, sizeof(dp));
  for(int i=0;i<=n;i++){
    for(int j=0;j<30;j++){
      for(int k=0;k<30;k++){
        for(int f=0;f<2;f++){
          for(int g=0;g<2;g++){
            dp[i][j][k][f][g] = -1;
          }
        }
      }
    }
  }
  cout << ddp(0, 27, 27, false, false) << endl;

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