#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 500 + 1;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    int target = n*(n+1)/2;
    if (target%2) {
        cout << 0 << endl;
        return;
    }
    target /= 2;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-i;
            if (left >= 0) {
                (dp[i][j] += dp[i-1][left]) %= M;
            }
        }
    }
    cout << dp[n-1][target] << endl;

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