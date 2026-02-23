#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = (int)4e18;

void solve(){

  int n, m; cin >> n >> m;

  vector<int> p(n+2), v(n+2);
  for(int i=1;i<=n;i++){
      cin >> p[i] >> v[i];
  }

  vector<vector<int>> prefdp(n+2, vector<int>(m+1, -inf));
  vector<vector<int>> sufdp(n+3, vector<int>(m+1, -inf));

  prefdp[0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int w=0;w<=m;w++){
      prefdp[i][w] = prefdp[i-1][w];
      if(w >= p[i] && prefdp[i-1][w-p[i]] != -inf){
        prefdp[i][w] = max(prefdp[i][w], prefdp[i-1][w-p[i]] + v[i]);
      }
    }
  }

  sufdp[n+1][0] = 0;
  for(int i=n;i>=1;i--){
    for(int w=0;w<=m;w++){
      sufdp[i][w] = sufdp[i+1][w];
      if(w >= p[i] && sufdp[i+1][w-p[i]] != -inf){
        sufdp[i][w] = max(sufdp[i][w], sufdp[i+1][w-p[i]] + v[i]);
      }
    }
  }

  for(int i=1;i<=n+1;i++){
    for(int w=1;w<=m;w++){
      sufdp[i][w] = max(sufdp[i][w], sufdp[i][w-1]);
    }
  }

  int best = 0;
  for(int w=0;w<=m;w++){
    best = max(best, prefdp[n][w]);
  }

  string ans(n, 'B');

  for(int i=1;i<=n;i++){
    int best1 = -inf;
    for(int w=0;w<=m;w++){
      if(prefdp[i-1][w] == -inf) continue;
      best1 = max(best1, prefdp[i-1][w] + sufdp[i+1][m-w]);
    }

    int best2 = -inf;
    if(p[i] <= m){
      for(int w=0;w<=m-p[i];w++){
        if(prefdp[i-1][w] == -inf) continue;
        best2 = max(best2, prefdp[i-1][w] + v[i] + sufdp[i+1][m-p[i]-w]);
      }
    }

    if(best2 < best) ans[i-1] = 'C';
    else if(best1 < best) ans[i-1] = 'A';
    else ans[i-1] = 'B';
  }

  cout << ans << endl;
}

signed main(){
  Fast_IO()
  int t = 1;
  // cin >> t;
  for(int i=1;i<=t;i++){
      solve();
  }
}
