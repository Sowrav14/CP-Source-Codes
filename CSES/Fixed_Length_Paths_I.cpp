#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 1;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, k;
vector<int> g[N];
int sz[N];
int tot, done[N];
// total node, done decomposition, parent of centeroid.

/* Centeroid Decomposition Processing */

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


int cnt[N]{1};
int ans = 0;
int mxdepth;

void dfs(int u, int p, bool f, int depth){
    if(depth > k) return;
    mxdepth = max(mxdepth, depth);
    
    if(f) cnt[depth]++;
    else ans += cnt[k - depth];

    for(auto v : g[u]){
        if(!done[v] and v != p) dfs(v, u, f, depth+1);
    }
}
/* finding centeroids one by one */
void decompose(int u, int pre) {
    tot = 0;
    calc_sz(u, pre);
    int cen = find_cen(u, pre);
    done[cen] = 1;
    mxdepth = 0;
    for(auto v : g[cen]){
        if(v == pre || done[v]) continue;
        dfs(v, cen, false, 1);
        dfs(v, cen, true, 1);
    }
    fill(cnt+1, cnt+mxdepth+1, 0);
    for(auto v : g[cen]) {
        if(v == pre || done[v]) continue;
        decompose(v, cen);
    }
}


void solve(){

    cin >> n >> k;
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    decompose(1, 0);
    cout << ans << endl;
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