#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, x; cin >> n >> x;
  int less = 0, greater = 0, equal = 0;
  for(int i=0;i<n;i++){
    int val; cin >> val;
    if(val < x) less++;
    else if(val > x) greater++;
    else equal++;
  }

  if(less == 0 or greater == 0){
    cout << "Yes" << endl;
    return;
  }
  if(equal > 0){
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl; 

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