#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5000 + 10;
const int M = 998244353;
const int inf = 1e12;

int n;
int a[N];
int dp[N][N];

int go(int i, int sum){
    if(i == n+1) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    
    int ans = 0;
    int add = ceil((a[i] + sum) / 2.0);
    if(add < a[i]) add = a[i];
    ans = add % M;
    
    ans = (ans%M + go(i+1, sum)%M)%M;
    ans = (ans%M + go(i+1, sum + a[i])%M)%M;
    
    return dp[i][sum] = ans;
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    memset(dp, -1, sizeof(dp));
    cout << go(1, 0) << endl;

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