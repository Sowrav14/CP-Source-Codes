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
  if(k == n or k == 2 or k == 4) return cout << -1 << endl, void();

  int sz = k - 2;
  int hf = sz / 2;
  string t = string(hf, '(') + string(hf, ')');

  string s = "";
  while(s.size() + sz <= n) s += t;
  int rem = n - s.size();
  if(rem == 2){
    s = '(' + s + ')';
  } else {
    s += string(rem / 2, '(') + string(rem / 2, ')');
  }
  s = s.substr(0, n);
  cout << s << endl;

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