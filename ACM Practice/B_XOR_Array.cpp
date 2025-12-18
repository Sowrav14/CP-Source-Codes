#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int> a{1, 2, 4, 8, 4, 2};
vector<int> b{16, 32, 64, 128, 64, 32};

void solve(){

  int n; cin >> n;
  int l, r; cin >> l >> r;
  vector<int> b(n+1, 0);
  for(int i=1;i<=n;i++) b[i] = i;
  b[l-1] = r;
  for(int i=1;i<=n;i++) cout << (int)(b[i] ^ b[i-1]) << " ";
  cout << endl;

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