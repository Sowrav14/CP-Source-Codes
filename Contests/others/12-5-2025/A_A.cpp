#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<string> month{
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
};

void solve(){

  string s; cin >> s;
  int k; cin >> k;
  int idx = -1;
  for(int i=0;i<12;i++){
    if(s == month[i]){
      idx = i;
      break;
    }
  }

  idx = (idx + k) % 12;
  cout << month[idx] << endl;

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