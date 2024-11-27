#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;

int n, m;
vector<int>a, b;
vector<vector<int>>dp;

int go(int i, int j){
    if(i == n + 1) return 0;
    if(j == m + 1) return inf;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = inf;
    ans = min(ans, go(i, j+1));
    int x = a[i-1] + b[j];
    int it = upper_bound(a.begin(), a.end(), x) - a.begin();
    // cout << it << endl;
    if(it != i) ans = min(ans, m - j + go(it, j));
    return dp[i][j] = ans;
}

void solve(){

    cin >> n >> m;
    a.clear(); b.clear(); dp.clear();
    a.resize(n+1, 0); b.resize(m+1, 0);
    dp.resize(n+1, vector<int>(m+1, -1));
    // cout << a.size() << " " << b.size() << endl;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }

    int ans = go(1, 1);
    if(ans >= inf){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }

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