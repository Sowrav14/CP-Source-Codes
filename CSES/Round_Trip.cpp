/*
 * @file Round_Trip.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * @problem: cycle Detection and Retrival in undirected graph.
 * @approach: DFS
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N =2e5 + 10;
vector<int>g[N];
int vis[N], p[N];
int s=-1,d=-1;


bool dfs(int u, int par){
    vis[u] = 1; p[u] = par;
    bool flag = false;
    for(auto v : g[u]){
        if(!vis[v]){
            flag |= dfs(v, u);
        } else if(v != par and par != -1){
            if(s == -1) s = v, d = u;
            flag = true;
        }
    }
    return flag;
}

bool rundfs(int n){
    bool flag = false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            flag |= dfs(i, -1);
        }
    }
    return flag;
}


void solve(){

    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    if(!rundfs(n)){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // cout << s << " " << d << endl;
    // for(int i=1;i<=n;i++) cout << p[i] << " "; cout << endl;
    int u = d; vector<int>ans;
    while(u != s){
        ans.push_back(u);
        u = p[u];
    } ans.push_back(s), ans.push_back(d);

    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " "; cout << endl;
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