#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N =2e5 + 10;
vector<int>g[N];
int vis[N], st[N];
int timer = 0;
int flag = 0;
void dfs(int u){
    vis[u] = 1;
    st[u] = ++timer;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        } else if(flag == 0 and st[v] - timer > 1){
            flag = 1;
            vis[u] = 2;
            vis[v] = 2;
        }
    }
}


void solve(){

    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(1);
    for(int i=1;i<=n;i++) cout << vis[i] << " "; cout << endl;

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