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
  int odd = 0;
  vector<int> even;
  for(int i=0;i<n;i++){
    int x; cin >> x;
    if(x % 2) odd = max(odd, x);
    else even.push_back(x);
  }
  sort(even.rbegin(), even.rend());

  if(odd == 0){
    for(int i=0;i<n;i++) cout << 0 << " ";
    cout << endl;
    return;
  }

  if(even.size() == 0){
    for(int i=0;i<n;i++){
      if(i % 2 == 0) cout << odd << " ";
      else cout << 0 << " ";
    }
    cout << endl;
    return;
  }
  int cnt = n - even.size();
  cout << odd << " ";
  int x = odd;
  for(int i=1;i<=even.size();i++){
    cout << x + even[i-1] << " ";
    x += even[i-1];
  }
  int j = 0;
  for(int i=even.size()+1;i<n;i++){
    if(j%2 == 0){
      if(cnt > 2){
        cout << x - even.back() << " ";
      } else {
        cout << 0 << " ";
      }
    } else {
      cout << x << " ";
    }
    j++;
    cnt--;
  }

  cout << endl;

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