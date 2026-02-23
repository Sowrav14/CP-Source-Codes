#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, k; cin >> n >> k;
  map<int, int> mp;
  queue<int> q;
  q.push(n);
  mp[n] = 0;
  while(!q.empty()){
    int x = q.front(); q.pop();
    if(!mp.count(x/2)) {
      mp[x/2] = mp[x] + 1;
      q.push(x/2);
    }
    if(!mp.count((x+1)/2)) {
      mp[(x+1)/2] = mp[x] + 1;
      q.push((x+1)/2);
    }
  }

  mp.count(k) ? cout << mp[k] << endl : cout << -1 << endl;

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