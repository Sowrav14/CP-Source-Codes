#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 1e5+10;
vector<int>g[N];
int vis[N];
int sub[N];

void dfs(int u){
    vis[u] = 1;
    sub[u] = 1;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
            sub[u] += sub[v];
        }
    }
    cout << u << " " << sub[u] << endl;
}


void solve(){

    int n,k; cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);

    for(int i=1;i<=n;i++) cout << sub[i] << " "; cout << endl;

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