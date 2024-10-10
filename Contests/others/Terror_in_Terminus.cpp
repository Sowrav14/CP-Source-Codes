#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#pragma GCC optimize("O3,unroll-loops")
const int N = 1e5 + 9, LG = 18;
vector<int> g[N];
int par[N][LG+1], dep[N], sz[N];


void reset(int n){
    for(int i=0;i<=n;i++){
        g[i].clear();
        dep[i] = 0;
        sz[i] = 0;
        for(int j=0;j<LG;j++){
            par[i][j] = 0;
        }
    }
}


// dfs for processing parents, depths and sizes of nodes...
void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i < LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

// returns the lowest common ancestor of node (u, v)
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG-1; k >= 0; k--) {
        if (dep[par[u][k]] >= dep[v]){
             u = par[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LG-1; k >= 0; k--){
        if (par[u][k] != par[v][k]) {
            u = par[u][k], v = par[v][k];
        }
    }
    return par[u][0];
}

// return the kth parent of node (u).
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG-1; i++){
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

    int n; cin >> n;
    reset(n);
    // graph input...
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int q; cin >> q;
    // answer queries...
    while (q--) {
        int u, v; cin >> u >> v;
        // cout << dist(u, v) << endl;
        int k = dist(u, v) / 2;
        int kk = dist(u, v) - k;
        // cout << go(u, v, k) << endl;
        // cout << lca(u, v) << endl;

        int x = kth(u, k);
        int y = kth(v, kk);
        if(abs(dist(u, x) - dist(v, x)) < 2) {
            cout << x << endl;
        } else{
            cout << y << endl;
        }
        // cout << kth(u, k) << " " << kth(v, kk) << " " << dist(x, u) << " " << dist(x, v) << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}