#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int G = 3;

int addmod(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int submod(int a,int b){ a-=b; if(a<0) a+=MOD; return a; }
int mulmod(ll a,ll b){ return (int)( (a*b) % MOD ); }
int powmod(int a, ll e=MOD-2){ ll r=1, x=a; while(e){ if(e&1) r=r*x%MOD; x=x*x%MOD; e>>=1; } return (int)r; }

// iterative NTT
void ntt(vector<int>& a, bool invert) {
    int n = (int)a.size();
    static vector<int> rev;
    static vector<int> roots{0,1};
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n,0);
        for (int i = 0; i < n; ++i)
            rev[i] = (rev[i>>1] >> 1) | ((i&1) << (k-1));
    }
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    if ((int)roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int z = powmod(G, (MOD - 1) >> (k+1));
            for (int i = 1 << (k-1); i < (1<<k); ++i) {
                roots[2*i] = roots[i];
                roots[2*i+1] = mulmod(roots[i], z);
            }
            ++k;
        }
    }
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2*len) {
            for (int j = 0; j < len; ++j) {
                int u = a[i+j];
                int v = mulmod(a[i+j+len], roots[len+j]);
                a[i+j] = addmod(u, v);
                a[i+j+len] = submod(u, v);
            }
        }
    }
    if (invert) {
        reverse(a.begin() + 1, a.end());
        int inv_n = powmod(n, MOD-2);
        for (int & x : a) x = mulmod(x, inv_n);
    }
}

vector<int> multiply_trunc(const vector<int>& a, const vector<int>& b, int need) {
    if (a.empty() || b.empty()) return {};
    int na = (int)a.size(), nb = (int)b.size();
    int real_need = min(need, na + nb - 1);
    int sz = 1;
    while (sz < na + nb - 1) sz <<= 1;
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(sz); fb.resize(sz);
    ntt(fa, false); ntt(fb, false);
    for (int i = 0; i < sz; ++i) fa[i] = mulmod(fa[i], fb[i]);
    ntt(fa, true);
    fa.resize(real_need);
    if ((int)fa.size() > need) fa.resize(need);
    return fa;
}

vector<int> poly_power_trunc(vector<int> base, long long exp, int deg_limit) {
    // base[0] may be zero; here base is log(1+x) with base[0]=0
    vector<int> res(1,1); // polynomial '1'
    while (exp > 0) {
        if (exp & 1LL) res = multiply_trunc(res, base, deg_limit+1);
        exp >>= 1LL;
        if (exp) base = multiply_trunc(base, base, deg_limit+1);
    }
    if ((int)res.size() > deg_limit+1) res.resize(deg_limit+1);
    else res.resize(min((int)res.size(), deg_limit+1));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    if(!(cin>>N>>K)) return 0;
    // Edge cases
    if (K > N) {
        // No outputs? As per problem, K <= N guaranteed. But handle anyway.
        return 0;
    }
    // factorials and inv factorials
    vector<int> fact(N+1), ifact(N+1), inv(N+1);
    fact[0]=1;
    for(int i=1;i<=N;i++) fact[i]=mulmod(fact[i-1], i);
    ifact[N]=powmod(fact[N]);
    for(int i=N;i>0;i--) ifact[i-1]=mulmod(ifact[i], i);
    for(int i=1;i<=N;i++) inv[i]=mulmod(fact[i-1], ifact[i]); // inverse of i

    if (K == 0) {
        // s(0,0)=1, s(n>0,0)=0
        // output s(0,0) ... s(N,0) according to prompt? Problem asks s(K,K)... s(N,K) so K=0 => s(0,0)..s(N,0)
        for (int n=0;n<=N;n++){
            int val = (n==0) ? 1 : 0;
            cout<<val;
            if (n!=N) cout << ' ';
        }
        cout<<"\n";
        return 0;
    }

    // Build series g(x) = log(1+x) = sum_{i>=1} (-1)^{i-1} x^i / i
    vector<int> g(N+1);
    g[0]=0;
    for (int i=1;i<=N;i++){
        int sign = (i%2==1)? 1 : (MOD-1);
        g[i] = mulmod(sign, inv[i]); // (-1)^{i-1} / i mod
    }

    // compute g(x)^K truncated to degree N
    vector<int> powg = poly_power_trunc(g, K, N);

    // divide by K!
    int inv_kfact = ifact[K]; // multiply coefficients by ifact[K]
    for (int i=0;i<(int)powg.size();++i) powg[i] = mulmod(powg[i], inv_kfact);

    // s(n,K) = n! * coeff_of_x^n in powg
    // powg may have size <= N+1, missing higher coefficients are zero
    // output s(K,K) ... s(N,K)
    bool first=true;
    for (int n=K;n<=N;n++){
        int coeff = 0;
        if (n < (int)powg.size()) coeff = powg[n];
        int ans = mulmod(fact[n], coeff);
        if (!first) cout << ' ';
        first = false;
        cout << ans;
    }
    cout << '\n';
    return 0;
}


/*

  Falling factorial: x^{\underline{n}} = x * (x-1) * (x-2) * ... * (x-n+1) = prod_{i=0}^{n-1} (x - i)
  = sum_{k=0}^{n} s(n,k) * x^k
  where s(n,k) is Stirling number of the first kind.

  Raising factorial: x^{\overline{n}} = x * (x+1) * (x+2) * ... * (x+n-1) = prod_{i=0}^{n-1} (x + i)
  = sum_{k=0}^{n} S(n,k) * x^{\underline{k}}
  where S(n,k) is unsigned Stirling number of the second kind.

*/


/*

  Stirling number of first kind
  s(n, k) : number of permutations of n elements with exactly k disjoint cycles.
  ex. s(3, 2) = 3: (1)(23), (2)(13), (3)(12)
      (1) (23) means cycle with 1 alone and cycle with 2 and 3.
  Recurrence:
    s(n, k) = s(n-1, k-1) + (n-1) * s(n-1, k)
    base: s(0,0)=1; s(n,0)=0 for n>0; s(0,k)=0 for k>0; s(n,n)=1 for n>=0; s(n,1)=(n-1)!
  
  For fixed n, we can compute all s(n,k) for k=0..n using polynomial method:
    x^{\underline{n}} = sum_{k=0}^{n} s(n,k) * x^k
    LHS: = prod_{i=0}^{n-1} (x - i)
    We can build this polynomial using divide & conquer and NTT multiplication.
    Then coefficients give s(n,0)..s(n,n).
    ex. for n=3:
      P(x) = (x-0)(x-1)(x-2)
           = ((x-0)(x-1)) * (x-2)
           = (x^2 - x) * (x-2)
           = x^3 - 3x^2 + 2x
           = 1*x^3 + (-3)*x^2 + 2*x + 0
      So s(3,0)=0, s(3,1)=2, s(3,2)=-3, s(3,3)=1

    how to compute P(x) efficiently for large n?
    We can use divide & conquer:
    build_poly(l, r):
        if l >= r: return polynomial '1' (coeff [1])
        if l + 1 == r: return polynomial (x - l) (coeff [-l, 1])
        m = (l + r) / 2
        left = build_poly(l, m)
        right = build_poly(m, r)
        return multiply(left, right) -> multiply two polynomials using NTT

    Then call build_poly(0, n) to get P(x).



    For fixed k, we can compute all s(n,k) for n=k..N using generating function method:
    Generating function:
      G_k(x) = sum_{n>=k} s(n,k) * x^n / n! = (log(1+x))^k / k!
    So to get s(n,k) for n=k..N:
      1. Build series g(x) = log(1+x) = sum_{i>=1} (-1)^{i-1} * x^i / i
        g(x) = log(1+x) = x - x^2/2 + x^3/3 - x^4/4 + ...
      2. Compute g(x)^k truncated to degree N using fast exponentiation(bigmode(a^b) similar) and polynomial multiplication
      3. Divide coefficients by k! (multiply by inv(k!))
      4. s(n,k) = n! * coeff_of_x^n in G_k(x)

*/


/*

  Stirling number of second kind
  S(n, k) : number of ways to partition n labeled elements into k nonempty unlabeled subsets.
  ex. S(3, 2) = 3: {1}|{2,3}, {2}|{1,3}, {3}|{1,2}
  Recurrence:
    S(n, k) = S(n-1, k-1) + k * S(n-1, k)
    base: S(0,0)=1; S(n,0)=0 for n>0; S(0,k)=0 for k>0; S(n,n)=1 for n>=0; S(n,1)=1 for n>=1.
  


*/