#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 1;
const int M = 998244353;
const int inf = 1e12;

int ans[N];
int f[N],invf[N];

// Big Mod
int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (ret * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ret;
}

// Calculating factorials and inverse factorial
void fact_invfact(){
    f[0] = 1;
    for(int i=1;i<N;i++){
        f[i] = (f[i-1] * i) % M;
    }

    // calculate fact inverse
    invf[N-1] = A_pow_B(f[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        invf[i] = (invf[i+1] * (i+1)) % M;
    }
}

// Calculating nCr
int nCr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (f[n]%M * invf[n-r]%M * invf[r]%M) % M ; 
}

// Calculating nPr
int nPr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n] * invf[n-r]) % M;
}

void precompute() {
    fact_invfact();
    for(int i=1;i<N;i++){
        ans[i] = (i%2 ? ans[i-1] : (ans[i-1] ^ nCr(i, i/2)));
    }
}

void solve(){

    int n; cin >> n;
    cout << (ans[n] ^ (n%2)) << '\n';

}


signed main(){
    Fast_IO()
    precompute();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}