#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;



void solve(){

    int n; cin >> n;
    vector<vector<int>> g(n+1, vector<int>());
    vector<int> deg(n+1, 0);
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int root = -1;
    for(int i=1;i<=n;i++){
        if(deg[i] == 2){
            root = i;
            break;
        }
    }
    if(root == -1){
        cout << "NO" << endl;
        return;
    }

    vector<pair<int,int>> ans;
    function< void(int, int, bool) > dfs = [&](int u, int p, bool f) -> void {
        for(auto v : g[u]){
            if(v != p){
                if(f) ans.push_back({u, v});
                else ans.push_back({v, u});
                dfs(v, u, 1 - f);
            }
        }
    };

    ans.push_back({root, g[root].front()});
    dfs(g[root].front(), root, 0);
    
    ans.push_back({g[root].back(), root});
    dfs(g[root].back(), root, 1);

    // cout << ans.size() << endl;
    cout << "YES" << endl;
    for(auto [u, v] : ans){
        cout << u << " " << v << endl;
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