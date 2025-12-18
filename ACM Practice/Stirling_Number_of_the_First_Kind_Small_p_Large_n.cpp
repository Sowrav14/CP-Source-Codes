#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Solution outline (implemented below):
We use the identity over F_p:
(x)_n = prod_{i=0}^{q-1} (x^p - x) * (x)_r  where n = q*p + r, 0 <= r < p.
Expand (x^p - x)^q = sum_{j=0}^q (-1)^{q-j} C(q,j) x^{p*j + q - j}.
Let (x)_r = sum_{t=0}^r c_t x^t (r < p so small).
We want coefficient of x^{A p + B} (k = A*p + B).
For each t, we need to see if there exists j such that
p*j + q - j = A*p + B - t  =>  j*(p-1) = q*p - (A*p + B - t).
Because p-1 divides left side, we can check congruence mod (p-1). Since p ≡ 1 (mod p-1),
the congruence simplifies and there is at most one t in [0,r] that satisfies it.
Compute that t (if any), compute the corresponding j (call it a'), check bounds 0<=a'<=q.
Then coefficient is c_t * (-1)^{q-a'} * C(q,a') mod p.
We precompute factorials and inverse factorials modulo p for Lucas theorem (p <= 5000),
and precompute all (x)_r coefficients for r=0..p-1.
Per query work is O( log_p(q) ) (for Lucas) plus O(1) checks.
*/

int pmod; // prime p

int modpow(int a, long long e) {
    int res = 1;
    a %= pmod;
    while(e){
        if(e & 1) res = (res * a) % pmod;
        a = (a * a) % pmod;
        e >>= 1;
    }
    return res;
}

vector<int> fact, invfact;

// nCk modulo p using precomputed fact/invfact for 0..p-1
int nCk_small(int n, int k) {
    if(k < 0 || k > n) return 0;
    return ( (fact[n] * invfact[k]) % pmod * invfact[n-k] ) % pmod;
}

// Lucas theorem for nCk % p where p is prime
int nCk_lucas(long long n, long long k) {
    if(k < 0 || k > n) return 0;
    int res = 1;
    while(n > 0 || k > 0) {
        int ni = n % pmod;
        int ki = k % pmod;
        if(ki > ni) return 0;
        res = (res * nCk_small(ni, ki)) % pmod;
        n /= pmod;
        k /= pmod;
    }
    return res;
}

int32_t main(){
    Fast_IO()
    int T;
    if(!(cin >> T >> pmod)) return 0;
    fact.assign(pmod, 0);
    invfact.assign(pmod, 0);
    fact[0] = 1;
    for(int i=1;i<pmod;i++) fact[i] = (fact[i-1] * i) % pmod;
    invfact[pmod-1] = modpow(fact[pmod-1], pmod-2);
    for(int i=pmod-2;i>=0;i--) invfact[i] = (invfact[i+1] * (i+1)) % pmod;

    // Precompute coefficients of (x)_r for r = 0..p-1
    // coeffs[r][t] = coefficient of x^t in (x)_r  (0 <= t <= r)
    vector<vector<int>> coeff(pmod, vector<int>(pmod, 0));
    for(int r = 0; r < pmod; r++){
        // start with poly = 1
        vector<int> poly(1,1); // degree 0
        for(int i = 0; i < r; i++){
            // multiply poly by (x - i)
            vector<int> npoly(poly.size() + 1, 0);
            for(size_t d = 0; d < poly.size(); d++){
                // contribution to x^{d+1} from x * poly[d]
                npoly[d+1] = (npoly[d+1] + poly[d]) % pmod;
                // contribution to x^{d} from (-i) * poly[d]
                int add = (pmod - (i % pmod)) % pmod;
                add = (add * poly[d]) % pmod;
                npoly[d] = (npoly[d] + add) % pmod;
            }
            poly.swap(npoly);
        }
        for(int t = 0; t <= r; t++) coeff[r][t] = poly[t] % pmod;
    }

    // For each test case
    for(int ti = 0; ti < T; ti++){
        unsigned long long n_in, k_in;
        cin >> n_in >> k_in;
        // handle simple cases
        if(k_in > n_in){
            cout << 0 << "\n";
            continue;
        }
        long long n = (long long)n_in;
        long long k = (long long)k_in;
        long long q = n / pmod;
        int r = (int)(n % pmod);
        long long a = k / pmod;
        int b = (int)(k % pmod);

        // u = q - a
        long long u = q - a;
        // We need t in [0, r] satisfying: (u*p - b + t) % (p-1) == 0
        // since p ≡ 1 (mod p-1), u*p ≡ u (mod p-1), so condition simplifies to:
        // (u - b + t) ≡ 0 (mod p-1)  => t ≡ b - u (mod p-1)
        int modm = (pmod - 1);
        int t0;
        if(modm == 0){
            // p == 1? impossible since p is prime >=2. Safe-guard.
            t0 = 0;
        } else {
            long long rhs = ( (long long)b - (u % modm) ) % modm;
            if(rhs < 0) rhs += modm;
            t0 = (int)rhs; // in [0, p-2]
        }
        if(t0 > r){
            cout << 0 << "\n";
            continue;
        }
        // Compute a' = (u*p - b + t0) / (p-1)
        // Need to ensure divisible (it is by construction) and 0 <= a' <= q
        // Use 128-bit for safety
        __int128 numer = (__int128)u * (__int128)pmod - (__int128)b + (__int128)t0;
        long long ap1 = (pmod - 1);
        if(ap1 == 0){
            cout << 0 << "\n";
            continue;
        }
        if(numer % ap1 != 0){
            cout << 0 << "\n";
            continue;
        }
        long long aprime = (long long)(numer / ap1);
        if(aprime < 0 || aprime > q){
            cout << 0 << "\n";
            continue;
        }
        // coefficient from B^q at the required degree is (-1)^{q-aprime} * C(q, aprime) mod p
        int comb = nCk_lucas(q, aprime);
        int sign = (( (q - aprime) & 1 ) ? (int)( (pmod - 1) ) : 1);
        int term = coeff[r][t0]; // c_t
        int ans = ( ( ( (long long)term * comb ) % pmod ) * sign ) % pmod;
        cout << ans << "\n";
    }

    return 0;
}
