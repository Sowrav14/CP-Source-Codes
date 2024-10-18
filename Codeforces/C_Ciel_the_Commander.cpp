/**
 * @file Centeroid Decomposition.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-10-15
 * @copyright Copyright (c) 2024
 * @topic: Centeroid Decomposition of tree.
 * @see_problems:
 *              - https://cses.fi/problemset/task/2079
 *              - 
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int> g[N];
int sz[N];
int tot, done[N], cenpar[N];
// total node, done decomposition, parent of centeroid.

/* DFS to calculate size of every subtree */
void calc_sz(int u, int p) {
    tot ++;
    sz[u] = 1;
    for (auto v : g[u]) {
        if(v == p || done[v]) continue;
        calc_sz(v, u);
        sz[u] += sz[v];
    }
}

/* find the centeroid */
int find_cen(int u, int p) {
    for (auto v : g[u]) {
        if(v == p || done[v]) continue;
        else if(sz[v] > tot / 2) return find_cen(v, u);
    }
    return u;
}

/* finding centeroids one by one */
void decompose(int u, int pre) {
    tot = 0;
    calc_sz(u, pre);
    int cen = find_cen(u, pre);
    cenpar[cen] = pre;
    done[cen] = 1;
    for(auto v : g[cen]) {
        if(v == pre || done[v]) continue;
        decompose(v, cen);
    }
}

/* Reset the inital tree and construct the decomposed tree */
/* Return the root of centeroid decomposed tree */
int cTree(){
    decompose(1, 0);
    for(int i = 1; i <= n; i++) g[i].clear();
    int root;
    for(int i = 1; i <= n; i++) {
        g[cenpar[i]].push_back(i);
        g[i].push_back(cenpar[i]);
        if (cenpar[i] == 0) root = i;
    }
    return root;
}

int dep[N];
void dfs(int u, int p = 0) {
    for(auto v : g[u]) {
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}


void solve(){

    cin >> n;

    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = cTree();
    dfs(root);
    for(int i=1;i<=n;i++){
        cout << char(dep[i] + 'A') << " \n"[i==n];
    }

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