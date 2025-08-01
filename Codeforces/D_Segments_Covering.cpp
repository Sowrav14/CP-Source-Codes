#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int modinv(int a) {
    int res = 1, b = M - 2;
    while (b) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
 

void solve(){

    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> seg(m+1, vector<pair<int,int>>());
    int tot = 1;
    for(int i=1;i<=n;i++){
        int l, r, p, q; cin >> l >> r >> p >> q;
        int pr = (p%M * modinv(q)%M)%M;
        int npr = (q%M - p%M + M)%M;
        npr = (npr%M * modinv(q)%M)%M;
        int pro = (pr%M * modinv(npr)%M)%M;
        seg[--l].push_back({r, pro});
        tot = (tot%M * npr%M)%M;
    }
    vector<int> dp(m+1, -1);
    function<int(int)> recur = [&](int u) -> int {
        if(u >= m) return 1;
        if(dp[u] != -1) return dp[u];

        int ret = 0;
        for(auto [v, p] : seg[u]){
            ret = (ret%M + (p%M * recur(v)%M)%M)%M;
        }
        return dp[u] = ret;
    };
    int res = recur(0);
    res = (res%M * tot%M)%M;
    cout << res << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}