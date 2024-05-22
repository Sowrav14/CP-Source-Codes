#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
vector<int>g[N];
int vis[N];


void dfs(int u){
    vis[u] = 1;
    for(auto v : g[u]) if(!vis[v]) dfs(v);
}


void solve(){

    int n,m; cin >> n >> m;
    vector<int>indegree(n+1, 0), d(n+1, -1), p(n+1, -1);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }

    dfs(1);
    if(vis[n] == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0) q.push(i);
    }
    d[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v : g[u]){
            if(d[u] != -1 and d[v] < d[u] + 1){
                d[v] = d[u] + 1;
                p[v] = u;
            }
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    stack<int>path;
    int v = n;
    while(v != -1){
        path.push(v);
        v = p[v];
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