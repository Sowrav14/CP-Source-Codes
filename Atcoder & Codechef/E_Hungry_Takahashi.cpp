#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;


void solve(){

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
        }
    }
    vector<int> a(n+m);
    for(int i=1;i<n+m;i++) cin >> a[i];

    auto check = [&](int x) -> bool {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -inf));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i >= 1) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j >= 1) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(i == 1 and j == 1) dp[i][j] = x;
                if(dp[i][j] < 0) continue;
                dp[i][j] += g[i][j];
                dp[i][j] -= a[i+j-1];
            }
        }
        return dp[n][m] >= 0;
    };

    int ans = inf;
    int l = 0, r = inf;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << endl;

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