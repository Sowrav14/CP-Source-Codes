#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n), dp(n, 1);
    int ans = 0;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=1;i<n;i++){
        if(v[i] >= v[i-1]) dp[i] = dp[i-1] + 1;
        else ans += (dp[i-1] * (dp[i-1] + 1)) / 2;
    }
    ans += (dp[n-1] * (dp[n-1] + 1)) / 2;
    cout << ans << endl;

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