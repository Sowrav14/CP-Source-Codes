#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<pair<int,int>> g[N];
int x[N], vis[N];
int deg[N];


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i];
    
    for(int i=1;i<n;i++){ 
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        deg[u]++; deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(deg[i] == 1)
            q.push(i);

    int ans=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(vis[v])continue;
            ans += 1LL * abs(x[u]) * w;
            x[v] += x[u];
            x[u] = 0;
            if(--deg[v] == 1) q.push(v);
        }
    }
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