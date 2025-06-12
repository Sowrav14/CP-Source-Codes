#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int f[N],invf[N];


// Big Mod
int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%M * a%M) % M;
        }
        a = (1ll * a%M * a%M) % M;
        b >>= 1;
    }
    return ret;
}



// Calculating factorials and inverse factorial
void fact_invfact(){
    f[0] = 1;
    for(int i=1;i<N;i++){
        f[i] = (1ll * f[i-1]%M * i%M) % M;
    }

    // calculate fact inverse
    invf[N-1] = A_pow_B(f[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        invf[i] = (1ll * invf[i+1]%M * (i+1)%M) % M;
    }
}


// Calculating nCr
int nCr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M * invf[r]%M) % M ; 
}


// Calculating nPr
int nPr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M) % M;
}

void solve(){

    vector<int> items;
    int n = 0;
    int down = 1;
    for(int i=0;i<26;i++){
        int x; cin >> x;
        if(x == 0) continue;
        items.push_back(x);
        n += x;
        down = (down%M * f[x]%M) % M;
    }
    int odd = (n + 1) / 2;
    int even = n - odd;

    // knapsack for partitioning the items into two groups
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(auto item : items) {
        for(int w = n; w >= item; w--) {
            dp[w] += dp[w - item];
        }
    }

    int ways = dp[odd];
    // cout << ways << endl;
    int up = (f[even]%M * f[odd]%M) % M;
    up = (up%M * ways%M) % M;
    down = A_pow_B(down, M - 2);
    int ans = (up%M * down%M) % M;
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    fact_invfact();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}