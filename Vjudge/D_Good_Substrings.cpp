/**
 * @file D_Good_Substrings.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-11-08
 * @copyright Copyright (c) 2024
 * @tag: String Hashing
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1500 + 9;

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

void solve(){

    string s; cin >> s;
    string ss; cin >> ss;
    vector<int>a(26, 0);
    for(int i=0;i<26;i++){
        a[i] = ss[i] - '0';
    }
    int k; cin >> k;

    vector<pair<int,int>>hashes;

    for(int i=0;i<s.size();i++){
        int cnt = 0;
        pair<int,int>hash = {0, 0};
        for(int j=i;j<s.size();j++){
            cnt += a[s[j] - 'a'] == 0;
            if(cnt > k) break;
            // cout << i << " " << j << " " << cnt << endl;
            hash.first = (hash.first + 1LL * pw[j-i].first * s[j] % MOD1) % MOD1;
            hash.second = (hash.second + 1LL * pw[j-i].second * s[j] % MOD2) % MOD2;
            hashes.push_back(hash);
        }
    }
    int ans = 0;
    sort(hashes.begin(), hashes.end());
    pair<int,int> p = {-1, -1};
    for(int i=0;i<hashes.size();i++){
        if(hashes[i] == p){
            continue;
        }
        ans++;
        p = hashes[i];
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    prec();
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}