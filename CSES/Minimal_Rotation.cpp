#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// calculate (a^b) % mod
int power(long long n, long long k, const int mod) {
    int ans = 1 % mod;
    n %= mod;
    if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = ans * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}

// define mods and calculate powers and inverse_powers...
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];

void prec() {
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}
struct Hashing {
    int n;
    string s; // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    // get hash from (l...r)
    pair<int, int> get_hash(int l, int r) { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    // get hash from (1...n)
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};

void solve(){

    string s; cin >> s;
    s += s;
    int n = s.size() / 2;

    Hashing hs(s);

    int k = 1;
    for(int i=2;i<=n;i++){
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int lm = (lo + hi) / 2;
            if(hs.get_hash(i, i + lm) == hs.get_hash(k, k + lm)){
                lo = lm + 1;
            } else{
                hi = lm - 1;
            }
        }
        if(lo <= n - 1){
            if(s[i + lo - 1] < s[k + lo - 1]){
                k = i;
            }
        }
    }
    cout << s.substr(k-1, n);

}


signed main(){
    Fast_IO();
    prec();
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}