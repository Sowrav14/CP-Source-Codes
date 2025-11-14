#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, m; cin >> n >> m;
  int ans = 0;
  vector<int> a(n+1, 0);
  for(int i=1;i<=m;i++){
    int u, v, x; cin >> u >> v >> x;
    if(!a[u] and !a[v]){
      a[u] = a[v] = x;
    } else {
      int temp = a[u];
      a[u] = a[v] + x;
      a[v] = temp + x;
    }
  }
  for(int i=1;i<=n;i++){
    ans = max(ans, a[i]);
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