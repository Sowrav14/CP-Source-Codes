#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int>d(n+1);
    d[1] = 1;
    function<void(int,int)> dfs = [&](int u, int p) -> void {
        for(auto v : g[u]){
            if(v == p) continue;
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    double ans = 0;
    for(int i=1;i<=n;i++){
        ans += (1.0 / d[i]);
    }
    cout << fixed << setprecision(20) << ans << endl;

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