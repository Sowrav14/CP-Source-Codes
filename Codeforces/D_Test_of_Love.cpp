#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
const int inf = 1e15;
int n,m,k;
string s;
int dp[N];

int recur(int i){
    if(i > n) return 0;
    if(s[i] == 'C') return inf;
    if(dp[i] != -1) return dp[i];
    int ans = inf;
    if(s[i] == 'W'){
        ans = min(ans, 1 + recur(i+1));
    }
    if(s[i] == 'L'){
        for(int j=1;j<=m;j++){
            ans = min(ans, recur(i+j));
        }
    }
    return dp[i] = ans;
}


void solve(){

    cin >> n >> m >> k;
    string ss; cin >> ss;
    s = 'L';
    s += ss;
    for(int i=0;i<=n;i++) dp[i] = -1;
    cout << (recur(0) > k ? "NO" : "YES") << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}