#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 500 + 1;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m;
vector<vector<int>>dp;

int recur(int r, int c){
    if(r == c) return 0;
    if(r == 1) return c - 1;
    if(c == 1) return r - 1;
    if(dp[r][c] != -1) return dp[r][c];

    int ans = inf;
    for(int i=1;i<r;i++){
        ans = min(ans, 1 + recur(i, c) + recur(r - i, c));
    }

    for(int j=1;j<c;j++){
        ans = min(ans, 1 + recur(r, j) + recur(r, c - j));
    }
    return dp[r][c] = ans;

}

void solve(){

    cin >> n >> m;
    dp.resize(n+1, vector<int>(m+1));
    for(int r=0;r<=n;r++){
        for(int c=0;c<=m;c++){
            if(r == c){
                dp[r][c] = 0;
            } else{
                dp[r][c] = inf;
                for(int k=1;k<r;k++){
                    dp[r][c] = min(dp[r][c], 1 + dp[k][c] + dp[r-k][c]);
                }
                for(int k=1;k<c;k++){
                    dp[r][c] = min(dp[r][c], 1 + dp[r][k] + dp[r][c-k]);
                }
            }
        }
    }

    cout << dp[n][m] << endl;

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