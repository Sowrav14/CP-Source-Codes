#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 998244353;
const int root = 3;
const int inf = 1e12;

/*
Compute Stirling numbers of the second kind S(n,k) for all k=0..n
using formula S(n,k) = (-1)^k * (U * V)[k], where
U_t = (-1)^t * t^n / t! and V_j = 1/j!
Convolution is done with NTT modulus 998244353.
*/

int modpow(int a, long long e){
    int r = 1;
    a %= M;
    while(e){
        if(e & 1) r = (r * a) % M;
        a = (a * a) % M;
        e >>= 1;
    }
    return r;
}

void ntt(vector<int> & a, bool invert){
    int n = a.size();
    static vector<int> rev;
    static vector<int> roots{0,1};
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n,0);
        for(int i=0;i<n;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (k-1));
    }
    for(int i=0;i<n;i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    if ((int)roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1<<k) < n) {
            // z is 2^{k+1}th root
            int z = modpow(root, (M-1) >> (k+1));
            for(int i = 1<< (k-1); i < (1<<k); ++i) {
                roots[2*i] = roots[i];
                roots[2*i+1] = (int)((1LL * roots[i] * z) % M);
            }
            ++k;
        }
    }
    for(int len = 1; len < n; len <<= 1){
        for(int i = 0; i < n; i += 2*len){
            for(int j = 0; j < len; ++j){
                int u = a[i+j];
                int v = (int)(1LL * a[i+j+len] * roots[len+j] % M);
                a[i+j] = u + v < M ? u+v : u+v-M;
                a[i+j+len] = u - v >= 0 ? u-v : u-v+M;
            }
        }
    }
    if(invert){
        reverse(a.begin() + 1, a.end());
        int inv_n = modpow(n, M-2);
        for(int & x : a) x = (int)(1LL * x * inv_n % M);
    }
}

vector<int> convolution(vector<int> a, vector<int> b){
    int need = (int)a.size() + (int)b.size() - 1;
    int sz = 1;
    while(sz < need) sz <<= 1;
    a.resize(sz);
    b.resize(sz);
    ntt(a, false);
    ntt(b, false);
    for(int i = 0; i < sz; ++i) a[i] = (int)(1LL * a[i] * b[i] % M);
    ntt(a, true);
    a.resize(need);
    return a;
}

void solve(){
    int n;
    cin >> n;
    // precompute factorials and invfacts up to n
    vector<int> fact(n+1), invfact(n+1);
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i] = (fact[i-1] * i) % M;
    invfact[n] = modpow(fact[n], M-2);
    for(int i=n;i>0;i--) invfact[i-1] = (invfact[i] * i) % M;

    vector<int> U(n+1), V(n+1);
    // U_t = (-1)^t * t^n / t!
    // V_j = 1/j!
    for(int t=0;t<=n;t++){
        int tn = (t==0 && n==0) ? 1 : modpow(t, n); // 0^0 = 1 by convention
        int sign = (t & 1) ? M-1 : 1;
        U[t] = (int)(1LL * sign * tn % M * invfact[t] % M);
        V[t] = invfact[t];
    }

    vector<int> D = convolution(U, V); // length <= 2n+1
    // S(n,k) = (-1)^k * D[k]
    for(int k=0;k<=n;k++){
        int val = (k < (int)D.size()) ? D[k] : 0;
        if(k & 1) val = (M - val) % M;
        cout << val << (k==n ? '\n' : ' ');
    }
}

signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
