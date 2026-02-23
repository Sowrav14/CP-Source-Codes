#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){
  int n, k; cin >> n >> k;
  vector<int> a(n+1);
  vector<vector<int>> pos(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
    pos[a[i]].push_back(i);
  }

  int l = 1, r = n - k + 1;
  int ans = 0;

  for(int i=0;i<=k-2;i++){
    if(pos[i].empty()) break;
    int mn = pos[i][0];
    int mx = pos[i].back();
    l = max(l, mn - k + 1);
    r = min(r, mx);
    if(l > r) break;
    ans = i + 1;
  }

  cout << ans << endl;
}

signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
