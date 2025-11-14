#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    // SCC
    vector<int> vis(n+1,0), order;
    function< void(int) > dfs1 = [&](int u) {
        vis[u] = 1;
        for(auto v : g[u]) 
            if(!vis[v]) 
                dfs1(v);
        order.push_back(u);
    };
    for(int i=1;i<=n;i++) 
        if(!vis[i]) 
            dfs1(i);

    vector<int> comp(n+1,-1);
    function<void(int, int)> dfs2 = [&](int u, int c) {
        comp[u] = c;
        for(auto v : rg[u]) 
            if(comp[v] == -1) 
                dfs2(v,c);
    };

    int cid = 0;
    reverse(order.begin(), order.end());
    for(auto u : order){
        if(comp[u] == -1) 
            dfs2(u, cid++);
    }

    // DAG
    vector<vector<int>> dag(cid);
    vector<int> indeg(cid, 0), sz(cid, 0);
    for(int i=1;i<=n;i++) sz[comp[i]]++;
    for(int u=1;u<=n;u++){
        for(auto v : g[u]){
            if(comp[u] != comp[v]){
                dag[comp[u]].push_back(comp[v]);
                indeg[comp[v]]++;
            }
        }
    }

    vector<vector<int>> dp(cid, vector<int>(k+1, 0));
    vector<int> topo;
    queue<int> q;
    for(int i=0;i<cid;i++) if(indeg[i] == 0) q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(auto v : dag[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }

    // DP 
    int ans=0;
    for(auto u : topo){
        dp[u][1] = sz[u];
        for(auto v : dag[u]){
            for(int x=1;x<k;x++){
                dp[v][x+1] = max(dp[v][x+1], dp[u][x]+sz[v]);
            }
        }
    }

    for(int i=0;i<cid;i++)
        for(int x=1;x<=k;x++)
            ans=max(ans, dp[i][x]);

    cout << ans << endl;
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
