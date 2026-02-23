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
  int cnt0 = 0, cnt1 = 0;
  for(char c : s){
    if(c == '0') cnt0++;
    else cnt1++;
  }

  if(cnt0 == 0 || cnt1 == 0){
    cout << "Bob" << endl;
    return;
  }

  vector<int> ans;
  for(int i=0;i<cnt0;i++){
    if(s[i] == '1') ans.push_back(i+1);
  }
  for(int i=cnt0;i<n;i++){
    if(s[i] == '0') ans.push_back(i+1);
  }
  if(ans.size() == 0){
    cout << "Bob" << endl;
    return;
  }
  cout << "Alice" << endl;
  cout << (int)ans.size() << endl;
  for(int i=0;i<(int)ans.size();i++){
    cout << ans[i] << (i == (int)ans.size()-1 ? "\n" : " ");
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