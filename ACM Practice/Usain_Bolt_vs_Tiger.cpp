#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*

  bolt to finish -> x
  bolt to tiger -> y
  tiger to finish -> x + y
  bolt speed -> u
  bolt -> x = u * tb => tb = x / u
  tiger acceleration -> a
  tiger -> y = 0.5 * a * tt^2 => tt^2 = 2y / a => tt = sqrt(2y / a)

*/

void solve(){

  int x, y, a, u; cin >> x >> y >> a >> u;
  y = x + y;
  double tb = (double)x / u;
  double tt = sqrt((2.0 * y) / a);
  cout << (tb < tt ? "Bolt" : "Tiger") << endl;

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