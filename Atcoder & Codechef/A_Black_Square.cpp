#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int p, q; cin >> p >> q;
  int x, y; cin >> x >> y;

  if(x >= p and x < p + 100 and y >= q and y < q + 100){
      cout << "Yes" << endl;
  }
  else{
      cout << "No" << endl;
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