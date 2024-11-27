#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int a[N];
int dp[N][N];

int game(int i, int j){
    if(i == j){
        return a[i];
    }
    if(dp[i][j] != -1) return dp[i][j];
    int ans = -inf;
    ans = max(ans, a[i] - game(i+1, j));
    ans = max(ans, a[j] - game(i, j-1));
    
    return dp[i][j] = ans;
}

void solve(){

    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++) cin >> a[i], sum += a[i];
    memset(dp, -1, sizeof(dp));
    cout << (game(1, n) + sum)/ 2 << endl;
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