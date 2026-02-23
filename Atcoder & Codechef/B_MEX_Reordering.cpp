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

  int f0 = 0, f1 = 0;
  for(int i=0;i<n;i++){
    if(a[i] == 0) f0++;
    if(a[i] == 1) f1++;
  }

  if(f0 == 0){
    cout << "NO" << endl;
    return;
  }
  if(f0 == 1){
    cout << "YES" << endl;
    return;
  }
  if(f1 == 0){
    cout << "NO" << endl;
    return;
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