#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
bool vis[N];
vector<int> g[N], r[N], vec;
int idx[N];


void dfs1(int u) {
    vis[u] = 1;
    for(auto v : g[u]) if(!vis[v]) dfs1(v);
    vec.push_back(u);
}

vector<int> comp;
void dfs2(int u) {
    comp.push_back(u);
    vis[u] = 1;
    for(auto v: r[u]) if(!vis[v]) dfs2(v);
}

void solve(){

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        r[v].push_back(u);
    }

    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs1(i);
    reverse(vec.begin(), vec.end());

    memset(vis, 0, sizeof vis);
    int scc = 0;
    for(auto u: vec) {
        if(!vis[u]) {
            comp.clear();
            dfs2(u);
            scc++;
            for(auto x: comp) idx[x] = scc;
        }
    }

    cout << scc << endl;
    for(int u = 1; u <= n; u++) {
        cout << idx[u] << " ";
    } cout << endl;

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