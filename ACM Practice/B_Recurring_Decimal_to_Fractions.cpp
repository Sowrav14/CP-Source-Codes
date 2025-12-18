#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, m; cin >> n >> m;
  string a, b; cin >> a >> b;
  string c = a + b;
  int x = stoll(c);
  int r = stoll(a);
  x -= r;
  string d = "";
  for(int i=0;i<m;i++) d += '9';
  for(int i=0;i<n;i++) d += '0';
  int y = stoll(d);

  int g = __gcd(x, y);
  if(g == 0) g = 1;
  cout << (x / g) << " " << (y / g) << endl;

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