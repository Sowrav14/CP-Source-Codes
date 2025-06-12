#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int n;
string s;
int dp[N];

int recur(int i){
    if(i >= n) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    if(i+3 < n and s[i] == s[i+2] and s[i+1] == s[i+3] and s[i] != s[i+1]){
        ans += recur(i + 3);
    }
    ans += recur(i + 1);
    ans %= M;
    return dp[i] = ans;
}


void solve(){

    cin >> n;
    cin >> s;
    for(int i=0;i<=n;i++) dp[i] = -1;
    cout << recur(0) << endl;

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