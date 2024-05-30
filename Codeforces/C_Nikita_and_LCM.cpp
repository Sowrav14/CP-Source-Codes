#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



void solve(){

    int n; cin >> n;
    map<int,int>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]] = 1;
    }
    sort(a.begin(), a.end());
    int dp[n+10][n+10];
    for(int i=0;i<n+5;i++){
        for(int cnt=0;cnt<n+5;cnt++){
            dp[i][cnt] = 0;
        }
    }
    for(int i=0;i<n;i++){
        dp[i][1] = a[i];
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        for(int cnt=0;cnt<=i+1;cnt++){
            int x = dp[i-1][cnt];
            int take = (x == 0 ? a[i] : (x * a[i]) / __gcd(x, a[i]));
            dp[i][cnt+1] = max(take, dp[i][cnt+1]);
            dp[i][cnt] = max(dp[i][cnt], x);
            if(!m[dp[i][cnt]]){
                ans = max(ans, cnt);
            }
            if(!m[dp[i][cnt+1]]){
                ans = max(ans, cnt);
            }
            // cout << i << " " << cnt << " " << x <<  " " << dp[i][cnt] << " "  << dp[i][cnt+1] << endl;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int cnt=0;cnt<=i+1;cnt++){
            cout << dp[i][cnt] << " ";
            if(!m[dp[i][cnt]]){
                ans = max(ans, cnt);
            }
        }
        cout << endl;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}