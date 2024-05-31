/*
 * @file Building_Teams.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * @problem: https://cses.fi/problemset/task/1668
 * @approach: Bipartite Graph
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
vector<int>g[N];
int vis[N], color[N];
int flag = 0;

void dfs(int u, int p){
    vis[u] = 1;
    color[u] = 1 - color[p];
    for(auto v : g[u]){
        if(!vis[v]) dfs(v, u);
        if(vis[v] and color[v] == color[u]) flag = 1;
    }
}

void solve(){

    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    if(flag){
        cout << "IMPOSSIBLE" << endl;
    } else{
        for(int i=1;i<=n;i++){
            cout << color[i] + 1 << " ";
        } cout << endl;
    }
}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}