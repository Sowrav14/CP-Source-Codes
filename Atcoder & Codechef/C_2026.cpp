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
  int ans = 0;
  map<int, int> sq;
  for(int i=1;i<=n;i++){
    int x2 = i * i;
    int y2 = n - x2;
    int y = sqrtl(y2);
    if(y <= i) break;;
    // ans += y - i;
    sq[i] = y;
  }
  // cout << ans << endl;
  vector<int> res;
  for(auto it : sq){
    int x = it.first;
    int y = it.second;
    for(int i = x + 1; i <= y; i++){
      res.push_back(x * x + i * i);
    }
  }
  sort(res.begin(), res.end());
  vector<int> fin;
  for(int i=0;i<res.size();i++){
    int j = i;
    while(j < res.size() && res[j] == res[i]){
      j++;
    }
    int count = j - i;
    if(count == 1){
      fin.push_back(res[i]);
    }
    i = j - 1;
  }
  cout << fin.size() << endl;
  for(auto it : fin){
    cout << it << " ";
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