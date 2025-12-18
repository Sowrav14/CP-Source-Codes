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

  if(n < 4){
      for(int x : a) cout << x << " ";
      cout << endl;
      return;
  }

  vector<int> p, q;
  for(int i=0;i<n;i++){
      if(i%2==0) p.push_back(a[i]);
      else q.push_back(a[i]);
  }

  
  if(n == 4){
    if(a[0] > a[2]) {
      swap(a[0], a[2]);
      swap(a[1], a[3]);
    }
    for(int x : a) cout << x << " ";
    cout << endl;
    return;
  }

  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  vector<int> b;
  int i=0, j = 0;
  while(i<p.size() or j<q.size()){
      if(i<p.size()) b.push_back(p[i++]);
      if(j<q.size()) b.push_back(q[j++]);
  }
  for(int x : b) cout << x << " ";
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