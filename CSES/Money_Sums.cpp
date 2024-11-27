#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 100 * 1000;


void solve(){

    int n; cin >> n;
    vector<int>a(n, 0);
    for(int i=0;i<n;i++) cin >> a[i];
    int mx = n * 1000;
    vector<vector<bool>>dp(n+1, vector<bool>(mx+1, false));

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=mx;j++){
            dp[i][j] = dp[i-1][j];

            int left = j - a[i-1];
            if(left >= 0 and dp[i-1][left]){
                dp[i][j] = true;
            }
        }
    }

    set<int>s;
    for(int j=1;j<=mx;j++) if(dp[n][j]) s.insert(j);

    cout << s.size() << endl;
    for(auto i : s) cout << i << " "; cout << endl;

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