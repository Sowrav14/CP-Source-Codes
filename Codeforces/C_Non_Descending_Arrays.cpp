#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int n; 
int a[110], b[110];
int dp[110][2];

int recur(int i, int f){

    if(i == n) return 1;
    if(dp[i][f] != -1) return dp[i][f];

    int ans = 0;
    if(i == 0){
        ans += recur(i+1, 0); ans %= M;
        ans += recur(i+1, 1); ans %= M;
    } else {
        if(f){
            if(a[i] >= b[i-1] and b[i] >= a[i-1]){
                ans += recur(i+1, 0); ans %= M;
            }
            if(a[i] >= a[i-1] and b[i] >= b[i-1]) {
                ans += recur(i+1, 1); ans %= M;
            }
        } else {
            if(a[i] >= a[i-1] and b[i] >= b[i-1]){
                ans += recur(i+1, 0); ans %= M;
            }
            if(b[i] >= a[i-1] and a[i] >= b[i-1]){
                ans += recur(i+1, 1); ans %= M;
            }
        }
    }
    ans %= M;
    return dp[i][f] = ans;
}


void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << recur(0, 0) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}