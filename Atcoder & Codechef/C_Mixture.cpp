#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;



void solve(){

    int n; cin >> n;
    string s; cin >> s;

    int mx = (1ll << n);
    vector<vector<int>> dp(n, vector<int>(mx+10, -1));
    
    function<bool(int,int)> recur = [&](int i, int mask) -> bool {
        if(i >= n) return true;
        if(dp[i][mask] != -1) return dp[i][mask];
        bool ans = false;
        for(int j=0;j<n;j++){
            // cout << i << " -> " << j << endl;
            if(mask & (1ll << j)) continue;
            int nmask = mask | (1ll << j);
            // cout << i << " " << nmask << endl;
            if(s[nmask-1] == '1') continue;
            ans |= recur(i+1, nmask);
        }
        return dp[i][mask] = ans;
    };

    cout << (recur(0, 0) ? "Yes" : "No") << endl;

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