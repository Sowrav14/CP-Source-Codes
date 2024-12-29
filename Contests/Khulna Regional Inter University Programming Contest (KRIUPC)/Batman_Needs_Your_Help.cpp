#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/**
    A = abcded
    B = abacba

    initMatch - 3
        abc --- dedx
        xaba --- cba
    
    now find the palindromic prefix from ded / suffix from aba

    to find prefix palindrom 
        - hash the forward s
        - hash the backward s
        - iterate i and find where forward hash and backward hash is equal
*/

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

// find palindromic prefix using Hashing
string findPfix(string s){
    string rs = s; int n = s.size();
    reverse(rs.begin(), rs.end());
    Hashing fhs = Hashing(s);
    Hashing rhs = Hashing(rs);
    
    int sz = 1;
    for(int i=1;i<=n;i++){
        pair<int,int> fhv = fhs.get_hash(1, i);
        pair<int,int> rhv = rhs.get_hash(n-i+1, n);

        if(fhv == rhv){
            sz = i;
        }
    }
    return s.substr(0, sz);
}

void solve(){

    string a, b; cin >> a >> b;
    int n = a.size(); int m = b.size();
    int sz = min(n, m);

    int initMatch = 0;
    for(int i=0;i<sz;i++){
        if(a[i] != b[m-i-1]) break;
        initMatch++;
    }
    string ansA = a.substr(0, initMatch);
    string ansB = b.substr(m-initMatch, initMatch);
    string restA = a.substr(initMatch, n - initMatch);
    string restB = b.substr(0, m - initMatch);
    reverse(restB.begin(), restB.end());
    // cout << ansA << " " << ansB << endl;
    // cout << restA << " " << restB << endl;
    string resA = findPfix(restA);
    string resB = findPfix(restB);
    // cout << resA << " " << resB << endl;
    string res;
    if(resA.size() == resB.size()){
        res = min(resA, resB);
    } else {
        res = (resA.size() > resB.size() ? resA : resB);
    }
    cout << ansA + res + ansB << endl;

}

signed main(){
    Fast_IO()
    prec();
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}