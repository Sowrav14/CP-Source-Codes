#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 8000 + 10;
const int K = 800 + 10;
const int M = 1e9 + 7;
const int inf = 3e18;

int n, k;
int dp[K][N];
int a[N];
int pref[N];

int cost(int i, int j){
    if(i > j) return 0;
    int cnt = j - i + 1;
    int val = pref[j] - pref[i-1];
    return cnt * val;
}

void dcdp(int i,int l, int r, int optl,int optr){
    if(l > r) return;

    int m = (l + r) / 2;
    pair<int,int>best = {inf, l};
    for(int j=optl;j<=optr;j++){
        best = min(best, {dp[i-1][j] + cost(j+1, m), j});
    }
    dp[i][m] = best.first;
    int opt = best.second;

    dcdp(i, l, m - 1, optl, opt);
    dcdp(i, m + 1, r, opt, optr);
}

void solve(){

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = inf;
        }
    }
    for(int i=0;i<=n;i++) dp[1][i] = cost(1, i);
    for(int i=2;i<=k;i++) dcdp(i, 0, n, 0, n);

    cout << dp[k][n] << endl;

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