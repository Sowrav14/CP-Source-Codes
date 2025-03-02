#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
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
 
Hashing fhs;
Hashing rhs;
int n;
 
vector<int> even, odd;
void setter(){
    for(int i=1;i<=N;i+=2){
        odd.push_back(i);
        even.push_back(i+1);
    }
}
 
bool check(int x){
    int l = 1, r = x;
    while(r <= n){
        auto fh = fhs.get_hash(l, r);
        auto bh = rhs.get_hash(n-r+1, n-l+1);
        if(fh == bh) return true;
        l++, r++;
    }
    return false;
}
 
int generate(bool flag){
    vector<int> x = flag ? odd : even;
 
    int l = 0;;
    int r = upper_bound(x.begin(), x.end(), n) - x.begin() - 1;
 
    int ans = 0;
    while(l <= r){
        int m = (l + r) / 2;
 
        if(check(x[m])){
            ans = x[m];
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
 
    return ans;
}
 
void solve(){
 
    string s; cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    n = s.size();
    fhs = Hashing(s);
    rhs = Hashing(r);
 
    int ans = 0;
    // cout << generate(0) << " " << generate(1) << endl;
    ans = max(generate(0), generate(1));
 
    int i = 1;
    while(ans <= n){
        auto fh = fhs.get_hash(i, ans);
        auto bh = rhs.get_hash(n-ans+1, n-i+1);
        if(fh == bh){
            for(int j=i-1;j<ans;j++){
                cout << s[j];
            } cout << endl;
            break;
        }
        i++, ans++;
    }
 
}
 
 
signed main(){
    Fast_IO();
    prec();
    setter();
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}