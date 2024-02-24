#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 105;
int a[N];
int n;
int dp[N][N][N];

int recur(int x, int l, int r){

    if(x > n){
        return l <= n ? N : 0;
    }
    if(dp[x][l][r] != -1) return dp[x][l][r];

    int lb = max(1ll, x - a[x] + 1);
    int rb = min(x + a[x] - 1, n);

    int ll = l < x ? l : x + (r > x);
    int rr = max(r, x + 1);
    int ans = recur(x+1, ll, rr);

    ll = x + 1;
    rr = max(r, x + 1);
    if(lb <= l) ans = min(ans, 1 + recur(x+1, ll, rr));

    ll = (l == x ? x + 1 : l);
    rr = max(rb+1, r);
    ans = min(ans, 1 + recur(x+1, ll, rr));

    return dp[x][l][r] = ans;
}


void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    cout << recur(1, 1, 1) << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        memset(dp, -1, sizeof(dp));
        // cout << "Case " << t << ": ";
        solve();
    }
}