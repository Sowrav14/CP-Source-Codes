/**
 * @file Counting_Paths.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-11-29
 * @copyright Copyright (c) 2024
 * @solution: Difference array technique in tree...
 * @tag: LCA Prefix Tree
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int>g[N];
int prefix[N];


/*                                  LCA                                     */
const int LG = 18;
int par[N][LG+1], dep[N], sz[N];
// dfs for processing parents, depths and sizes of nodes...
void InitLCA(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) if (v != p) {
        InitLCA(v, u);
        sz[u] += sz[v];
    }
}

// returns the lowest common ancestor of node (u, v)
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) {
        if (dep[par[u][k]] >= dep[v]){
             u = par[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LG; k >= 0; k--){
        if (par[u][k] != par[v][k]) {
            u = par[u][k], v = par[v][k];
        }
    }
    return par[u][0];
}

// return the kth parent of node (u).
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG; i++){
        if (k & (1 << i)){
            u = par[u][i];
        }
    }
    return u;
}

// return distance from u to v.
int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}

// returns kth node from u to v, 0th node is u
int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    if (dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}
/*                                                                          */

void prefixer(int u, int p){
    for(auto v : g[u]){
        if(v == p) continue;
        prefixer(v, u);
        prefix[u] += prefix[v];
    }
}


void solve(){

    int n, q; cin >> n >> q;
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    InitLCA(1);
    while(q--){
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        int p = par[l][0];

        prefix[u]++;
        prefix[v]++;
        prefix[l]--;
        prefix[p]--;
    }
    prefixer(1, 0);
    for(int i=1;i<=n;i++) cout << prefix[i] << " \n"[i==n];
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