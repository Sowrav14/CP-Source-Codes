#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, -1)));
    function<bool(int, int, bool)> subset = [&](int i, int sum, bool taken) -> bool {
        if (i == n) {
            return taken && sum == 0;
        }
        if (dp[i][sum][taken] != -1) {
            return dp[i][sum][taken];
        }
        bool res = false;
        // Include the current element
        res |= subset(i + 1, (sum + a[i]) % 3, true);
        // Exclude the current element
        res |= subset(i + 1, sum, taken);
        return dp[i][sum][taken] = res;
    };

    cout << (subset(0, 0, 0) ? "Yes" : "No") << endl;

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