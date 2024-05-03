#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 10000+10;
vector<int>g[N];
int vis[N];

void reset(int n){
    for(int i=0;i<n;i++){
        g[i].clear();
        vis[i] = 0;
    }
}

void dfs(int u){
    vis[u] = 1;
    cout << u << " ";
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){

    int n; cin >> n;
    reset(n);

    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;

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