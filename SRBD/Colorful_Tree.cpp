#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 5e5 + 9, LG = 20;
vector<int> g[N];
int par[N][LG+1], dep[N], sz[N];
int depth[N], col[N]; 
string s;

// dfs for processing parents, depths and sizes of nodes...
void dfs(int u, int p = 0) {
    par[u][0] = p;
    depth[u] = depth[p] + 1;
    col[u] = col[p] + (s[u-1] == '1');
    dep[u] = dep[p] + (s[u-1] == '1');
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

// returns the lowest common ancestor of node (u, v)
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) {
        if (depth[par[u][k]] >= depth[v]){
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
    return depth[u] + depth[v] - (depth[l] << 1ll);
}

// returns kth node from u to v, 0th node is u
int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = depth[u] + depth[v] - (depth[l] << 1);
    assert(k <= d);
    if (depth[l] + k <= depth[u]) return kth(u, k);
    k -= depth[u] - depth[l];
    return kth(v, depth[v] - depth[l] - k);
}

void reset(int n) {
    for(int i=0;i<=n;i++){
        g[i].clear();
        dep[i] = 0;
        depth[i] = 0;
        col[i] = 0;
        sz[i] = 0;
        for(int j=0;j<=LG;j++) par[i][j] = 0;
    }
    s.clear();
}



void solve(){

    int n, q; cin >> n >> q;
    reset(n);
    // graph input...
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    cin >> s;
    depth[0] = 0; col[0] = 0; dep[0] = 0;
    dfs(1);
    // answer queries...
    while (q--) {
        int x, y; cin >> x >> y;
        int L = lca(x, y);
        cout << (col[x] + col[y] - 2 * col[L] + 1) << '\n';
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
