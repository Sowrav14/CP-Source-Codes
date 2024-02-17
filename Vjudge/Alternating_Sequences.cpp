#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



void solve(){

    int n; cin >> n;
    vector<int>v(n+10, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    vector<int>dp(n+10, 1);
    int ans = 1;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(abs(v[i]) > abs(v[j]) and max(v[i], v[j]) > 0 and min(v[i], v[j]) < 0){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    // for(int i=1;i<=n;i++) cout << dp[i] << " "; cout << endl;
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}