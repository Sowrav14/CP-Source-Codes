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
  string s; cin >> s;
  int odd = 0;
  vector<int> freq(26,0);
  for(int i=1;i<=n;i++){
    freq[s[i-1]-'a']++;
  }
  odd = 
  for(int i=0;i<26;i++){
    if(freq[i]>odd){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;

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