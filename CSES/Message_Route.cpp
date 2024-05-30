#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5+10;
vector<int>g[N];
int vis[N], d[N], p[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    d[s] = 0;
    p[s] = -1;
    vis[s] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
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

    bfs(1);

    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    stack<int>path;
    int u = n;
    while(u != -1){
        path.push(u);
        u = p[u];
    }
    cout << path.size() << endl;
    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
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