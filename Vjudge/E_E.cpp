#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 3000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

string s;
int dp[N][N];

int recur(int i, int j){
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    if(s[i] == s[j]){
        ans = recur(i+1, j-1);
    } else {
        ans = min(ans, 1 + recur(i+1, j));
        ans = min(ans, 1 + recur(i, j-1));
        ans = min(ans, 1 + recur(i+1, j-1));
    }

    return dp[i][j] = ans;
}


void solve(){

    cin >> s;
    int n = s.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout << recur(0, n - 1) << endl;

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