#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n+10), bit(n + 10, -inf) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] = max(val, bit[idx]);
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int sum = -inf;
        while(idx > 0){
            sum = max(sum, bit[idx]);
            idx -= (idx) & (-idx);
        }
        return sum;
    }
};



void solve(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  map<int,int> m;
  for(int i=0;i<n;i++) m[a[i]]++;
  int cnt = 1;
  for(auto &i : m) i.second = cnt++;
  for(int i=0;i<n;i++) a[i] = m[a[i]];
  BIT bit(cnt);
  bit.update(a[0], 0);
  cout << 0 << endl;
  for(int i=1;i<n;i++){
    // if(a[i] == 1) continue;
    int mx = bit.query(a[i] - 1);
    if(mx == -inf){
      cout << -1 << endl;
      continue;
    }
    cout << mx + 1 << endl;
    bit.update(a[i], mx + 1);
  }
  // cout << endl;

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