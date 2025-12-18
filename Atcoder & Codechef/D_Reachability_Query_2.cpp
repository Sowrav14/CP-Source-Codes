#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m;
vector<int> g[N];
int vis[N];

void dfs(int u){
  vis[u] = 1;
  for(auto v: g[u]){
    if(!vis[v]){
      dfs(v);
    }
  }
}

void solve(){

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int u, v; cin >> u >> v;
    g[v].push_back(u);
  }

  int q; cin >> q;
  while(q--){
    int t, v; cin >> t >> v;
    if(t == 1){
      if(!vis[v]) dfs(v);
    } else {
      if(vis[v]) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
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