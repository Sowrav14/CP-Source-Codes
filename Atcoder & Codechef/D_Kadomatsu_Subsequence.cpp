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
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  map<int,int> dp3, dp7;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(a[i] % 5 == 0){
      int x = a[i] / 5;

      int three = dp3.count(x) ? dp3[x] : 0;
      int seven = dp7.count(x) ? dp7[x] : 0;
      ans += (three * seven);
    }
    if(a[i] % 3 == 0){
      int x = a[i] / 3;
      dp3[x]++;
    }
    if(a[i] % 7 == 0){
      int x = a[i] / 7;
      dp7[x]++;
    }
  }
  dp3.clear();
  dp7.clear();
  for(int i=n-1;i>=0;i--){
    if(a[i] % 5 == 0){
      int x = a[i] / 5;

      int three = dp3.count(x) ? dp3[x] : 0;
      int seven = dp7.count(x) ? dp7[x] : 0;
      ans += (three * seven);
    }
    if(a[i] % 3 == 0){
      int x = a[i] / 3;
      dp3[x]++;
    }
    if(a[i] % 7 == 0){
      int x = a[i] / 7;
      dp7[x]++;
    }
  }

  
  cout << ans << endl;

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