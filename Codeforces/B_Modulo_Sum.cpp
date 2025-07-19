#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e3 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;



void solve(){

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(n >= m) return cout << "YES" << endl, void();
    vector< vector< vector<int>>> dp (n,
            vector< vector<int>> (m,
                    vector<int> (2, -1)));
    
    function< bool(int, int, bool)> is_possible = [&](int i, int sum, bool take) -> bool {
        if(i == n) return sum == 0 && take;
        if(dp[i][sum][take] != -1) return dp[i][sum][take];

        bool ans = false;
        ans |= is_possible(i + 1, sum, take);
        ans |= is_possible(i + 1, (sum + a[i]) % m, true);
        
        return dp[i][sum][take] = ans;
    };

    is_possible(0, 0, 0) ? cout << "YES\n" : cout << "NO\n";

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