#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

double dp[110][660];
int n, a, b;


void solve(){

    cin >> n >> a >> b;
    
    dp[0][0] = 1.0;
    for(int i=1;i<=n;i++){
        for(int s=1;s<=6*n;s++){
            for(int d=1;d<=6;d++){
                if(s-d>=0) dp[i][s] += dp[i-1][s-d];
            }
            dp[i][s] /= 6;
        }
    }
    
    double ans = 0;
    for(int i=a;i<=b;i++) ans += dp[n][i];
    // ans = round(ans * 1e6) / 1e6;
    cout << fixed << setprecision(6) << ans << endl;

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