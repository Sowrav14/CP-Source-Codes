#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int> g[N];
int subtree[N];
int par[N];

void dfs(int u, int p){
  subtree[u] = 1;
  par[u] = p;
  for(auto v : g[u]){
    if(v != p){
      dfs(v, u);
      subtree[u] += subtree[v];
    }
  }
}

void solve(){

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    subtree[i] = 0;
  }
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  for(int i=1;i<=n;i++){
    int mx = 0;
    for(auto v : g[i]){
      int sub = (v == par[i]) ? (n - subtree[i]) : subtree[v];
      mx = max(mx, sub);
    }
    if(n%2 == 0 and mx <= n/2) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;

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