#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e4 + 10;
vector<int>g[N];
int in[N], out[N], vis[N];

void dfs(int u){
    vis[u] = 1;

    for (auto v : g[u]){
        out[u] = 1;
        in[v] = 1;

        if (!vis[v]){
            dfs(v);
        }
    }
}

void solve(){

    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    int tin = 0, tout = 0;
    for(int i=1;i<=n;i++){
        // cout << ind[i] << " " << outd[i] << endl;
        tin += (in[i] > 0);
        tout += (out[i] > 0);
    }
    cout << tin << " " << tout << endl;
    cout << max((n - tin), (n - tout)) << endl;

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