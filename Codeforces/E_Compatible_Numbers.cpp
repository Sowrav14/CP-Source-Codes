#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int B = 22;
const int N = 1 << B;
const int M = 1e9 + 7;
const int inf = 1e12;

void solve(){

    int n; cin >> n;
    vector<int> a(n);
    vector<int> dp(N, inf);
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp[a[i]] = a[i];
    }

    for(int i=0;i<B;i++){
        for(int mask=0;mask<N;mask++){
            if(mask & (1 << i)){
                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    }

    for(int i=0;i<n;i++){
        int id = (~a[i]) & ((1 << B) - 1);
        if(dp[id] != inf){
            cout << dp[id] << " ";
        } else {
            cout << -1 << " ";
        }
    }

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