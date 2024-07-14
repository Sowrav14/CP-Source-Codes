#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 3e5 + 9, LG = 18;
vector<int> g[N];
int par[N][LG+1], dep[N], sz[N];

// dfs for processing parents, depths and sizes of nodes...
void dfs(int u, int p = -1) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
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

void solve(){

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1);
    while (q--) {
        int u, k; cin >> u >> k;
        cout << kth(u, k) << endl;
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