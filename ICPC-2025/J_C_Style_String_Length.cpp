#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  string s; cin >> s;
  int cnt = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '0') cnt++;
    else if(s[i] == '\\'){
      if(i+1 < s.size() and s[i+1] == '\\'){
        cnt++;
        i++;
      } else if(i+1 < s.size() and s[i+1] == '0'){
        return cout << cnt << endl, void();
      } else {
        return cout << "INVALID" << endl, void();
      }
    }
  }
  cout << cnt << endl;

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