#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 100 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

double dp[N][N][N];
double go(int r, int s, int p){
    if(r == 0) return 0.0;
    if(r and s == 0 and p == 0) return 1.0;
    if(dp[r][s][p] != -1.0) return dp[r][s][p];

    int tot = r*s + s*p + p*r;
    double ans = 0.0;
    if(r and s) ans += 1.0 * r * s * go(r, s-1, p);
    if(s and p) ans += 1.0 * s * p * go(r, s, p-1);
    if(p and r) ans += 1.0 * p * r * go(r-1, s, p);
    ans /= (1.0 * tot);
    return dp[r][s][p] = ans;
}

void reset(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
}

void solve(){

    int r, s, p; cin >> r >> s >> p;
    reset();
    cout << fixed << setprecision(12) << go(r, s, p) << endl;
    reset();
    cout << fixed << setprecision(12) << go(s, p, r) << endl;
    reset();
    cout << fixed << setprecision(12) << go(p, r, s) << endl;

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