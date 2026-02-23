#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, m; cin >> n >> m;
  vector<vector<int>> conf(n+1, vector<int>());
  for(int i=0;i<m;i++){
    int u, v; cin >> u >> v;
    conf[u].push_back(v);
    conf[v].push_back(u);
  }

  for(int i=1;i<=n;i++){
    int sz = conf[i].size();
    int rem = n - sz - 1;
    // cout << rem << endl;
    int ans = rem * (rem - 1) * (rem - 2);
    ans /= 6;
    cout << ans << " \n"[i == n];
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