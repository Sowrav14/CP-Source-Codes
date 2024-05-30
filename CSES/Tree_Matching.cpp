#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
vector<int>g[N];
int vis[N];
int cnt = 0;

void dfs(int u=1, int p=0){
    for(auto v : g[u]){
        if(v != p) dfs(v, u);
    }

    if(!vis[u] and !vis[p] and p!= 0){
        cnt++;
        vis[u] = vis[p] = 1;
    }
}

void solve(){

    int n; cin >> n;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();

    cout << cnt << endl;

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