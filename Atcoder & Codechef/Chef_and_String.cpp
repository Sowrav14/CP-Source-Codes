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
  string s; cin >> s;
  int ans = n * k - 1;
  string t = "";
  for(char c : s) if(c != 'I') t += c;
  int res = 0;
  for(int i=0;i<(int)t.size()-1;i++){
    if(t[i] != t[i+1]) res++;
  }
  ans -= res * k;
  if(t[0] != t.back()){
    ans -= (k - 1);
  }
  cout << ans << endl;

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