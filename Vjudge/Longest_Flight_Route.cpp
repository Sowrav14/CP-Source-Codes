#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5+10;
vector<int>g[N];
int vis[N];

// distance and parent store.
int d[N], p[N];
// single source bfs.
void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source] = 1;
    d[source] = 0;
    p[source] = -1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : g[v]){
            if(vis[u]) continue;
            q.push(u);
            vis[u] = 1;
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}

// shortest path from source to any vertex u.
void path(int u){
    if(!vis[u]) {
        cout << "No path" << endl;
        return;
    }

    vector<int> pth;
    for(int v=u;v!=-1;v=p[v]){
        pth.push_back(v);
    }
    reverse(pth.begin(), pth.end());
    for(auto v : pth) cout << v << " "; cout << endl;
    return;
}

void solve(){

    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
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