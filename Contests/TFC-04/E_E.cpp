#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int cost[26][26];

int n;
string s;
int take;
int dp[110][26][110];

int recur(int i, int p, int k){
    if(i == n) return 0;
    if(dp[i][p][k] != -1) return dp[i][p][k];

    int ans = -inf;
    for(int j=0;j<26;j++){
        if(i == 0){
            if(j == (s[i]-'a')) ans = max(ans, recur(i+1, j, k));
            else if(k < take) ans = max(ans, recur(i+1, j, k + 1));
            else ans = max(ans, recur(i+1, s[i]-'a', k));
        } else {
            if(j == (s[i]-'a')) ans = max(ans, cost[p][j] + recur(i+1, j, k));
            else if(k < take) ans = max(ans, cost[p][j] + recur(i+1, j, k + 1));
            else ans = max(ans, cost[p][s[i]-'a'] + recur(i+1, s[i]-'a', k));
        }
    }
    return dp[i][p][k] = ans;
}


void solve(){

    cin >> s;
    n = s.size();
    cin >> take;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        char a, b; cin >> a >> b;
        int c; cin >> c;
        cost[a-'a'][b-'a'] = c;
    }
    memset(dp, -1, sizeof(dp));

    cout << recur(0, 0, 0) << endl;

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