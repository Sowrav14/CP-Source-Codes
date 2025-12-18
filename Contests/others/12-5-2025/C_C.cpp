#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int fact[N];
void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

void solve(){

  int n, m; cin >> n >> m;
  
  vector<int> a, b;
  int at = 0, bt = 0;
  for(int i=0;i<n;i++){
    int x; cin >> x;
    char c; cin >> c;
    if(c == 'T') a.push_back(x);
    else at += x;
  }
  for(int i=0;i<m;i++){
    int x; cin >> x;
    char c; cin >> c;
    if(c == 'T') b.push_back(x);
    else bt += x;
  }

  int mt = max(at, bt);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int awt = 0, bwt = 0, awd = 0, bwd = 0;
  int azt = a.size(), bzt = b.size();
  int azd = n - azt, bzd = m - bzt;

  if(a.empty()){
    awt = 1;
  } else {
      int x = upper_bound(a.begin(), a.end(), mt - at) - a.begin();
      x = a.size() - x;
      awt = (fact[a.size() - 1]%M * x%M)%M;
  }
  if(b.empty()){
    bwt = 1;
  } else {
    int y = upper_bound(b.begin(), b.end(), mt - bt) - b.begin();
    y = b.size() - y;
    bwt = (fact[b.size() - 1]%M * y%M)%M;
  }

  awd = fact[n - a.size()];
  bwd = fact[m - b.size()];

  int wa = (awt%M * awd%M) % M;
  int wb = (bwt%M * bwd%M) % M;
  int w = (wa%M * wb%M) % M;
  cout << w << endl;

}


signed main(){
  Fast_IO()
  precompute_factorials();
  int t = 1;
  // cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}