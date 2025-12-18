// compile with: g++ -O2 -march=native -std=c++20 stirling_first_ntt.cpp -o stirling
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int G = 3;

int addmod(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int submod(int a,int b){ a-=b; if(a<0) a+=MOD; return a; }
int mulmod(ll a,ll b){ return (int)( (a*b) % MOD ); }
int powmod(int a,ll e=MOD-2){ ll r=1, x=a; while(e){ if(e&1) r=r*x%MOD; x=x*x%MOD; e>>=1; } return (int)r; }

// NTT implementation (iterative)
void ntt(vector<int> & a, bool invert) {
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
            // z = g^{(MOD-1) / (2^{k+1})}
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

// multiply two polynomials (mod MOD) using NTT
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    if (a.empty() || b.empty()) return {};
    int na = (int)a.size(), nb = (int)b.size();
    int need = na + nb - 1;
    int sz = 1;
    while (sz < need) sz <<= 1;
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(sz); fb.resize(sz);
    ntt(fa, false); ntt(fb, false);
    for (int i = 0; i < sz; ++i) fa[i] = mulmod(fa[i], fb[i]);
    ntt(fa, true);
    fa.resize(need);
    return fa;
}

// divide & conquer product of linear factors (x - i) for i in [l, r)
vector<int> build_poly(int l, int r) {
    if (l >= r) return vector<int>{1};
    if (l + 1 == r) {
        // polynomial x - l  => coefficients: constant = -l, x = 1
        int c = (MOD - (l % MOD)) % MOD;
        return vector<int>{c, 1};
    }
    int m = (l + r) >> 1;
    auto left = build_poly(l, m);
    auto right = build_poly(m, r);
    return multiply(left, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    if (N == 0) {
        cout << 1 << "\n";
        return 0;
    }
    // Build polynomial P(x) = prod_{i=0}^{N-1} (x - i)
    vector<int> poly = build_poly(0, N); // degree N, size N+1
    // poly[k] is coefficient of x^k
    // print s(N,0) ... s(N,N)
    // Ensure size N+1
    poly.resize(N+1);
    for (int k = 0; k <= N; ++k) {
        cout << poly[k] % MOD;
        if (k+1 <= N) cout << ' ';
    }
    cout << '\n';
    return 0;
}
