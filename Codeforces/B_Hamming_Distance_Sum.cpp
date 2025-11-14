#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  string a, b; cin >> a >> b;
  int n = a.size();
  int m = b.size();

  vector<pair<int,int>> cnt(n, {0, 0});
  for(int j=0;j<=m-n;j++){
    if(b[j] == '0') cnt[0].first++;
    else cnt[0].second++;
  }
  int r = m - n + 1;
  for(int i=1;i<n;i++){
    cnt[i] = cnt[i-1];
    if(b[r] == '0') cnt[i].first++;
    else cnt[i].second++;
    r++;
    if(b[i-1] == '0') cnt[i].first--;
    else cnt[i].second--;
  }
  // for(auto i : cnt) cout << i.first << " " << i.second << endl;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(a[i] == '0') ans += cnt[i].second;
    else ans += cnt[i].first;
  }
  cout << ans << endl;

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