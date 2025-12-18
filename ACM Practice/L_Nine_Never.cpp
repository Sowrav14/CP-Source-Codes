#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/* Just to get the pattern */
vector<int> max_groups_no_subset9(int x){
  const uint64_t FULL = ((1ULL<<51) - 1ULL); // keep bits 0..50
  vector<int> best, cur;
  function<void(int,int,uint64_t)> dfs = [&](int remain, int last, uint64_t mask){
    if(remain == 0){
      if(cur.size() > best.size()) best = cur;
      return;
    }
    // upper bound pruning: even if we use all parts = last, we can't beat best
    int ub = (int)cur.size() + (remain / last);
    if(ub <= (int)best.size()) return;

    for(int p = last; p <= remain; ++p){
      if(p == 9) continue; // single 9 is forbidden
      // compute new reachable subset-sum mask
      uint64_t shifted = (p < 64) ? (mask << p) : 0;
      shifted &= FULL;
      uint64_t newmask = mask | shifted;
      if((newmask >> 9) & 1ULL) continue; // would create a subset sum 9 -> skip
      cur.push_back(p);
      dfs(remain - p, p, newmask);
      cur.pop_back();
    }
  };

  // start with reachable sum {0} -> mask bit 0 set
  dfs(x, 1, 1ULL);
  return best;
}

// for 11, 13, 15, 17, 19, 21, 23, 25, 27, 29
// known optimal solutions
vector<int> store{4, 5, 6, 8, 9, 9, 9, 9, 9, 10};


void solve(){

  int n; cin >> n;
  if(n < 9){
    cout << n << endl;
  } else if(n % 2 == 0){
    cout << (n / 2) % M << endl;
  } else if(n <= 29){
    cout << store[(n - 11) / 2] << endl;
  } else {
    cout << (((n-11) / 2) + 1) % M << endl;
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