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
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<int>> freq(n+1);
    for(int i=0;i<n;i++){
        freq[a[i]].push_back(i);
    }

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i != 0) dp[i] = max(dp[i], dp[i-1]);

        int x = a[i];
        int j = lower_bound(freq[x].begin(), freq[x].end(), i) - freq[x].begin();
        if(j + x - 1 < freq[x].size()){
            j = j + x - 1;
        } else {
            continue;
        }
        j = freq[x][j]; 
        // cout << i << " " << j << endl;
        dp[j + 1] = max(dp[j  + 1], dp[i] + x);
    }
    for(int i=0;i<=n;i++) ans = max(ans, dp[i]);
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