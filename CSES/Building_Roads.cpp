#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
vector<int>g[N];
int vis[N];

void dfs(int u){
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}


void solve(){

    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int>cc;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cc.push_back(i);
            dfs(i);
        }
    }

    cout << cc.size() - 1 << endl;
    for(int i=1;i<cc.size();i++){
        cout << cc[i] << " " << cc[i-1] << endl;
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