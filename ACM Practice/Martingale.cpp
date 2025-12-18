#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Approach:
- Let E[v] be expected flips starting from capital v with stake X = 1.
- Consider the sequence until the first head or absorption:
  * If the first head occurs after k tails (k >= 0) and k < m where m = ceil(log2(v+1)),
    then net effect is v -> v+1 and flips used = k+1 (probability 1/2^{k+1}).
  * If at least m consecutive tails occur, then after m-th tail we have v - (2^m - 1) <= 0 and game ends at that flip (probability 1/2^m).
- Therefore:
  E[v] = (1 - 1/2^m) * E[v+1] + C(m),
  where C(m) = sum_{r=1..m} r / 2^r  + m / 2^m  (accounts for flips consumed by cases).
- Compute E[v] for v = 2N-1 down to 1 (E[0]=E[2N]=0). Answer is E[N].
*/

void solve(){
    int n;
    if(!(cin >> n)) return;
    int LIM = 2 * n;
    vector<double> E(LIM + 1, 0.0);

    // precompute pow2 and sums up to needed max m
    int maxm = 0;
    // find maximum m needed for v up to 2n-1: require 2^m >= (v+1) -> max v+1 = 2n -> m = ceil(log2(2n))
    {
        long long t = 1;
        while(t < (long long)(2*n)) { t <<= 1; maxm++; }
        if(maxm == 0) maxm = 1;
    }
    vector<double> pow2(maxm+2, 1.0);
    for(int i=1;i<=maxm+1;i++) pow2[i] = pow2[i-1]*2.0;
    vector<double> S(maxm+2, 0.0); // S[m] = sum_{r=1..m} r / 2^r
    for(int m=1;m<=maxm+1;m++){
        S[m] = S[m-1] + (double)m / pow2[m];
    }
    vector<double> C(maxm+2,0.0);
    for(int m=1;m<=maxm+1;m++){
        C[m] = S[m] + (double)m / pow2[m];
    }

    for(int v = LIM-1; v >= 1; v--){
        // compute m = ceil(log2(v+1))
        int need = v + 1;
        int m = 0;
        // find smallest m s.t. 2^m >= need
        // pow2 array holds 2^i as double, but safe to compute via shift
        long long p = 1;
        while(p < (long long)need){ p <<= 1; m++; }
        if(m == 0) m = 1;
        double q = 1.0 / pow2[m];
        E[v] = (1.0 - q) * E[v+1] + C[m];
    }

    cout.setf(std::ios::fixed); cout<<setprecision(12)<<E[n]<<endl;
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
