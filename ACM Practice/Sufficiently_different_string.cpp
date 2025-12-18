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
  int k; cin >> k;

  vector<bool> present(26, false);
  for(char c : s){
    present[c - 'a'] = true;
  }
  string t = "";
  for(int i=0;i<26;i++){
    if(!present[i]){
        t += (char)(i + 'a');
    } else {
      if(k > 0){
        t += (char)(i + 'a');
        k--;
      }
    }
  }
  if(t.size() < s.size()){
    cout << "NOPE" << endl;
  }else {
    cout << t.substr(0, s.size()) << endl;
  }

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