#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  string s, t; cin >> s >> t;
  for(int i=0;i<s.size();i++){
    s[i] = tolower(s[i]);
  }
  for(int i=0;i<t.size();i++){
    t[i] = tolower(t[i]);
  }

  int i = 0, j = 0;
  while(i < s.size() && j < t.size()){
    if(s[i] == t[j]){
      i++;
      j++;
    }
    else{
      if(t[j] == 'a' || t[j] == 'e' || t[j] == 'i' || t[j] == 'o' || t[j] == 'u' || t[j] == 'y'){
        j++;
      }
      else{
        cout << "Different" << endl;
        return;
      }
    }
  }
  if(i == s.size()){
    if(j == t.size()){
      cout << "Same" << endl;
      return;
    }
    while(j < t.size()){
      if(t[j] == 'a' || t[j] == 'e' || t[j] == 'i' || t[j] == 'o' || t[j] == 'u' || t[j] == 'y'){
        j++;
      }
      else{
        cout << "Different" << endl;
        return;
      }
    }
    cout << "Same" << endl;
  }
  else{
    cout << "Different" << endl;
  }

}


signed main(){
  Fast_IO()
  int t = 1;
  // cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}