#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;

int n, m;
vector<int>g[N];
int vis[N];
int gold[N];
int mx[N];

void dfs(int u){
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
        // dfs(v);
        mx[u] = max(mx[v], mx[u]);
        mx[u] = max(mx[u], gold[v]);
    }
}


void solve(){

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> gold[i];
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i=1;i<=n;i++) {
        mx[i] = -inf;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    // for(int i=1;i<=n;i++) cout << mx[i] << " "; cout << endl;
    int ans = -inf;
    for(int i=1;i<=n;i++){
        // cout << mx[i] << " ";
        if(mx[i] <= -inf) {
            continue;
        }
        // cout << mx[i] - gold[i] << endl;
        ans = max(ans, (mx[i] - gold[i]));
    }
    if(ans <= -inf) ans = 0;
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