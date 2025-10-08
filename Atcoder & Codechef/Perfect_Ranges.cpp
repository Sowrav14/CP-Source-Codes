#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) if(a[i] > b[i]) swap(a[i], b[i]);

    int ans = 1;
    vector<pair<int,int>> dp;
    for(int i=0;i<n;i++) dp.push_back({1, 0});
    for(int i=1;i<n;i++){
        if(a[i] > b[i-1]) {
            dp[i].first += dp[i-1].first + dp[i-1].second;
        } else if(a[i] > a[i-1]){
            dp[i].first += dp[i-1].first;
            if(b[i] > b[i-1]) dp[i].second += dp[i-1].second;
        } else {
            if(b[i] > a[i-1]) dp[i].second += dp[i-1].first;
            if(b[i] > b[i-1]) dp[i].second += dp[i-1].second;
        }
        ans += dp[i].first + dp[i].second;
    }
    
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