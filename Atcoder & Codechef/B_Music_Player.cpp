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
  int vol = 0, play = 0;
  while(n--){
    int x; cin >> x;
    if(x == 1){
      vol++;
    } else if(x == 2){
      if(vol > 0) vol--;
    } else {
      play = 1 - play;
    }

    cout << ((play && vol >= 3) ? "Yes" : "No") << endl; 
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