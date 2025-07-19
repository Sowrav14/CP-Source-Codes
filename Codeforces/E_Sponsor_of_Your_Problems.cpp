#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int n;
vector<int> a, b;
vector<vector<vector<vector<vector<int>>>>> dp;

int digitdp(int i, bool tl, bool tr, int ml, int mr, bool lz) {
    if (i == n) return ml + mr;
    
    if (dp[i][tl][tr][ml][mr] != -1)
        return dp[i][tl][tr][ml][mr];
    
    int ans = INT_MAX;
    int lo = tl ? a[i] : 0;
    int hi = tr ? b[i] : 9;
    if (i == 0) lo = max(lo, 1ll);
    
    for (int d = lo; d <= hi; d++) {
        int nml = ml + ((d == a[i] && (!lz || d != 0)) ? 1 : 0);
        int nmr = mr + ((d == b[i] && (!lz || d != 0)) ? 1 : 0);
        bool ntl = tl && (d == a[i]);
        bool ntr = tr && (d == b[i]);
        bool nlz = lz && (d == 0);
        
        int res = digitdp(i + 1, ntl, ntr, nml, nmr, nlz);
        ans = min(ans, res);
    }
    
    return dp[i][tl][tr][ml][mr] = ans;
}

void solve() {
    long long l, r; cin >> l >> r;
    
    a.clear();
    b.clear();
    while (r > 0) {
        b.push_back(r % 10);
        r /= 10;
    }
    while (l > 0) {
        a.push_back(l % 10);
        l /= 10;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    n = a.size();
    
    dp.assign(n + 1, vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)))));
    
    cout << digitdp(0, 1, 1, 0, 0, 1) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}