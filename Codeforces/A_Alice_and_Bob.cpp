#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, a; cin >> n >> a;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  sort(v.begin(), v.end());

  int x = upper_bound(v.begin(), v.end(), a) - v.begin();
  int up = n - x;
  x = lower_bound(v.begin(), v.end(), a) - v.begin();
  int down = x;

  if(up > down){
    cout << a + 1 << endl;
  } else {
    cout << a - 1 << endl;
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