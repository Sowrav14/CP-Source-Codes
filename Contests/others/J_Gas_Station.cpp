#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;

vector<pair<int,int>> g[N];

int dfs(int u, int p, int mid, int &cnt){
  int mx = 0, sec_mx = 0;
  for(auto &[v,w] : g[u]){
    if(v == p) continue;
    int ww = dfs(v, u, mid, cnt) + w;
    if(ww > mid){
      cnt++;
      ww = w;
    }
    if(ww >= mx){
      sec_mx = mx;
      mx = ww;
    } else if(ww > sec_mx){
      sec_mx = ww;
    }
  }
  if(mx + sec_mx > mid){
    cnt++;
    return 0;
  }
  return mx;
}

bool check(int mid, int k){
  int cnt = 0;
  dfs(1, 1, mid, cnt);
  return cnt <=  k;
}


void solve(){

  int n, k; cin >> n >> k;
  int l = -1, r = inf;
  for(int i=1;i<n;i++){
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
    l = max(l, w);
  }
  int ans = -1;
  while(l <= r){
    int m = (l + r) / 2;
    if(check(m, k)){
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;  
    }
  }
  cout << l << endl;

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