#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
struct chash {  /// use most bits rather than just the lowest ones
	const uint64_t C = (int)(2e18 * acos((long double)-1)) + 71;  // large odd number
	const int RANDOM = rng();
	 int operator()(int x) const { 
		return __builtin_bswap64((x ^ RANDOM) * C);
	}
};
template <class K, class V> using ht = gp_hash_table<K, V, chash>;
// ht<int, pair<int,int>> hm; // use

void solve(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  if(n <= 2){
    cout << "Yes" << endl;
    return;
  }
  sort(a.begin(), a.end());
  gp_hash_table<int, int> freq;
  for(int i=0;i<n;i++) freq[a[i]]++;

  

  for(int i=1;i<n-1;i++){
    // cout << "Checking for " << a[i] << endl;
    int mn = a[i];
    int diff = a.back() - mn;
    int mx = a[0] + diff;
    if(mx == a[i] and freq[mx] > 1){
      // cout << a[i] << " " << mx << " " << diff << endl;
      cout << "Yes" << endl;
      return;
    }
    else if(mx != a[i] and freq.find(mx) != freq.end()){
      // cout << a[i] << " " << mx << " " << diff << endl;
      cout << "Yes" << endl;
      return;
    }
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