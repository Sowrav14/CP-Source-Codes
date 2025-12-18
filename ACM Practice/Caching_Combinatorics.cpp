#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 5000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


/*
Approach (short):
- For each test we find the minimal prefix length k of B (0 <= k <= n) such that
  the suffix B[k..n-1] appears in the same relative order as in A.
  Practically: scan B from right to left and count how many elements form a strictly
  increasing sequence of positions in A; let r be that length, then k = n - r.
- If the suffix doesn't match A's relative order, answer is 0.
- Otherwise the number of valid operation sequences of length m equals S(m,k),
  the Stirling number of the second kind (number of ways to partition m labeled
  operations into k nonempty unlabeled blocks). If k > m answer is 0.
- We precompute Stirling numbers S(i,j) for all i,j up to max_m among testcases
  using recurrence: S(i,j) = S(i-1,j-1) + j * S(i-1,j), modulo MOD.
*/

const int MOD = 998244353;


int stirling[N][N];

void str(){
  stirling[0][0] = 1;
  for(int i=1;i<N;i++) {
    for(int j=1;j<=i;j++) {
      stirling[i][j] = (stirling[i-1][j-1] + (j * stirling[i-1][j]) % MOD) % MOD;
    }
  }
}


void solve(){
  int n, m; cin >> n >> m;
  vector<int> A(n), B(n);
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < n; i++) cin >> B[i];
  vector<int> pos(n+1, -1);
  for(int i = 0; i < n; i++) pos[A[i]] = i+1; // 1-based positions

  int r = 0;
  int last = n + 1;
  for(int i = n-1; i >= 0; i--){
      int p = pos[B[i]];
      if(p < last){
          last = p;
          r++;
      } else break;
  }
  int k = n - r;
  // verify suffix B[k..n-1] indeed has strictly increasing pos in A
  bool ok = true;
  int prev = 0;
  for(int i = k; i < n; i++){
      int p = pos[B[i]];
      if(p <= prev){ ok = false; break; }
      prev = p;
  }
  if(!ok){
      cout << 0 << endl;
      return;
  }
  if(k > m){
      cout << 0 << endl;
      return;
  }
  // We'll need S(m,k) precomputed externally by main; here we will query global table.
  // To allow that, we'll store the S table in a static-like place via global vector.
  // cout << m << " " << k << endl;
  int ans = 0;
  for(int i=0;i<=r;i++){
    ans = (ans + stirling[m][k+i]) % MOD;
  }
  cout << ans << endl;
}


signed main(){
  Fast_IO()
  str();
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}