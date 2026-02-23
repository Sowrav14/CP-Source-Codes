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
  vector<int> a(26, 0), b(26, 0);
  string s, t; cin >> s >> t;
  for(int i=0;i<n;i++){
      a[s[i]-'a'] = 1;
  }
  for(int i=0;i<m;i++){
      b[t[i]-'a'] = 1;
  }

  int q; cin >> q;
  while(q--){
    string ss; cin >> ss;
    vector<int> c(26, 0);
    for(auto x: ss){
        c[x-'a'] = 1;
    }

    int fa = 1, fb = 1;
    for(int i=0;i<26;i++){
      if(c[i] == 1 and a[i] == 0) fa = 0;
      if(c[i] == 1 and b[i] == 0) fb = 0;
    }

    if(fa == 1 and fb == 1){
        cout << "Unknown" << endl;
    }
    else if(fa == 1){
        cout << "Takahashi" << endl;
    }
    else if(fb == 1){
        cout << "Aoki" << endl;
    }
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