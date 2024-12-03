#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 19;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
double a[N][N];
double dp[1<<N];

double fishing(int mask){
    int fish = __builtin_popcount(mask);
    if(fish == n){
        return 1.0;
    }
    if(dp[mask] > -0.9) return dp[mask];
    double ans = 0;
    // which fish is killed
    for(int i=0;i<n;i++){
        if(mask & (1 << i)) continue;   // previous fish not present..
        double p = fishing(mask | (1 << i));
        double c = (fish * (fish + 1)) / 2;
        // how this fish can be eliminated
        double res = 0;
        for(int j=0;j<n;j++){
            if(mask & (1 << j)){ // this can eliminate
                res += a[j][i];
            }
        }
        ans += (p * (res / c));
    }
    return dp[mask] = ans;
}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << fixed << setprecision(6);
    for(int i=0;i<n;i++){
        cout << fishing(1<<i) << " ";
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