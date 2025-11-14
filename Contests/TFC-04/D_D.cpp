#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int dp[1100][1100];
int g[1100];
int n, d;

int recur(int i, int mask){
    if(i == n) {
        if(mask == ((1 << 10) - 1)) return 0;
        else return 11;
    }
    if(mask >= ((1 << 10) - 1)) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 11;
    int nmask = mask | g[i];

    ans = min(ans, 1 + recur(i+1, nmask));
    ans = min(ans, recur(i+1, mask));
    return  dp[i][mask] = ans;
}

void solve(){

    cin >> n >> d;
    for(int i=0;i<=n;i++){
        for(int j=0;j<1024;j++){
            dp[i][j] = -1;
        }
        for(int j=0;j<10;j++){
            g[i] = 0;
        }
    }
    // vector<vector<int>> g(n, vector<int>(10, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            char c; cin >> c;
            int x = c - '0';
            g[i] |= (1ll << x);
        }
        // cout << g[i] << endl;
    }
    int x = recur(0, 0);
    if(x <= 10){
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    // cout << recur(0, 0) << endl;

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