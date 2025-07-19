#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e9;


void solve(){

    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1, vector<pair<int,int>>());
    vector<int> ans(n+1, inf);
    for(int i=0;i<m;i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        ans[u] = min(ans[u], w);
        ans[v] = min(ans[v], w);
    }
    // for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i == n];
    vector<int> vis(n+1, 0);
    bool ok = true;
    function < void(int) > dfs = [&](int u) -> void{
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(max(ans[u], ans[v]) != w) {
                // cout << u << " " << v << " " << w << endl;
                ok = false;
            }
            if(!vis[v]){
                dfs(v);
            }
        }
    };
    
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    if(!ok){
        cout << -1 << endl;
    } else {
        for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i == n];
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