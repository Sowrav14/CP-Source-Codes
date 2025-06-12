#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e17;


void solve(){

    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    vector<vector<int>> g(n+1, vector<int>());
    for(int i=0;i<n-1;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(n+1);
    ans[1] = a[1];
    function<void(int, int, int, int)> dfs = [&](int u, int p, int mx, int mn) {
        for(auto v : g[u]){
            if(v == p) continue;
            // cout << "entering " << endl;
            // cout << v << " " << u << " " << mx << " " << mn << endl;
            int nmx = max(a[v], a[v] - mn);
            int nmn = min(a[v], a[v] - mx);
            ans[v] = nmx;
            // cout << v << " " << u << " " << nmx << " " << nmn << endl;
            // cout << "exiting " << endl; 
            dfs(v, u, nmx, nmn);
        }
    };
    dfs(1, 0, a[1], a[1]);
    for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;

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