#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int t, n;
double p;
double dp[N][N];

double recur(int i, int cur){
    if(i == t) return n - cur;
    if(cur == 0) return n;
    if(dp[i][cur] != -1.0) return dp[i][cur];
    double ans = 0.0;
    ans += 1.0 * p * recur(i+1, cur-1);
    ans += 1.0 * (1.0 - p) * recur(i+1, cur);
    return dp[i][cur] = ans;
}

void solve(){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1.0;
        }
    }
    cin >> n >> p >> t;
    cout << fixed << setprecision(10) << recur(0, n) << endl;

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