#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n; cin >> n;
  if(n == 2 || n == 3) return cout << n << endl, void();
  if(n % 2 == 0) return cout << 0 << endl, void();
  if(n % 3 == 0) return cout << ((n/3)%2) << endl, void();
  cout << 1 << endl;

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