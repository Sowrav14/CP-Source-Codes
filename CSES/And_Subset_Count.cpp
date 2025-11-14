#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Count non-empty subsets whose bitwise AND equals k for all k = 0..n.
Steps:
1. freq[x] = count of elements equal to x.
2. Superset SOS DP: dp[mask] = count of elements ai s.t. (ai & mask) == mask.
3. subsets with AND ⊇ mask = 2^{dp[mask]} - 1.
4. Inclusion–Exclusion over supersets to get exact AND = mask.
5. Output answers for k = 0..n.
*/

int powerMod(int a,int b){
  int ans=1;
  while(b){
    if(b&1) ans=(ans*a)%M;
    a=(a*a)%M;
    b>>=1;
  }
  return ans;
}

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  
  int maxA = *max_element(a.begin(), a.end());
  int LOG = 0;
  while((1 << LOG) <= maxA) LOG++;
  int maxMask = (1 << LOG);

  vector<int> freq(maxMask, 0);
  for(auto x : a) freq[x]++;

  vector<int> dp = freq;

  // Superset SOS DP
  for(int bit=0;bit<LOG;bit++){
    for(int mask=0;mask<maxMask;mask++){
      if(mask & (1 << bit)) continue;
      dp[mask] += dp[mask | (1 << bit)];
    }
  }
  // for(int i=0;i<=4;i++) cout << dp[i] << " "; cout << endl;

  vector<int> res(maxMask,0);
  for(int mask=0;mask<maxMask;mask++){
    if(dp[mask] == 0) continue;
    res[mask] = (powerMod(2, dp[mask]) - 1 + M) % M;
  }

  // Inclusion–Exclusion (Superset subtraction)
  for(int bit=0;bit<LOG;bit++){
    for(int mask=0;mask<maxMask;mask++){
      if(mask & (1 << bit)) continue;
      res[mask] = (res[mask] - res[mask | (1 << bit)] + M) % M;
    }
  }

  for(int k=0;k<=n;k++){
    if(k < maxMask) cout << res[k] << " ";
    else cout << 0 << " ";
  }
  cout << endl;
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
