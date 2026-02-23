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
  vector<int> a(k+1);
  for(int i=1;i<=k;i++) a[i] = n;

  if(k%2){
    for(int i=1;i<=k;i++) cout << a[i] << " \n"[i==k];
    return;
  }

  a[k] = 0;
  if(__builtin_popcountll(n) < 2){
    for(int i=1;i<=k;i++) cout << a[i] << " \n"[i==k];
    return;
  }

  int i=0;
  int x = n;
  int j = 63 - __builtin_clzll(x);
  x ^= (1LL << j);
  j = 63 - __builtin_clzll(x);

  while(i <= j){
    a[k-1] ^= (1ll << i);
    a[k] ^= (1ll << i);
    // cout << a[k-1] << " " << a[k] << endl;
    i++;
  }

  for(int i=1;i<=k;i++) cout << a[i] << " \n"[i==k];

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