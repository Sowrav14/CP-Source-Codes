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
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];


  for(int i=0;i<n;i++){
    double sum = 0;
    for(int j=0;j<n;j++){
      if(i != j){
        sum += (double)((1.0 * a[j]) / (a[j] + a[i]));
      }
    }
    cout << fixed << setprecision(9) << 1 + sum << " ";
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