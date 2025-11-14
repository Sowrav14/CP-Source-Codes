#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s; cin >> s;
    int n = s.length();

    if(n == 1){
      cout << 1 << endl;
      return;
    }


    char prev = '#';
    for(int i=0;i<n;i++){
      if(s[i] == '*'){
        if(prev == '*'){
          return void(cout << -1 << endl);
        } else if(prev == '>'){
          return void(cout << -1 << endl);
        } else {
          prev = '*';
        }
      } else if(s[i] == '<'){
        if(prev == '*'){
          return void(cout << -1 << endl);
        } else if(prev == '>'){
          return void(cout << -1 << endl);
        } else {
          prev = '<';
        }
      } else {
        prev = '>';
      }
    }
    int ans = -1;
    int cnt = 0;
    for(int i=0;i<n;i++){
      if(s[i] == '*' || s[i] == '<'){
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 0;
      }
    }
    ans = max(ans, cnt);
    cnt = 0;
    for(int i=0;i<n;i++){
      if(s[i] == '*' || s[i] == '>'){
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 0;
      }
    }
    ans = max(ans, cnt);
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