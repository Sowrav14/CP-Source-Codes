#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int>g[N];
int c[N];
set<int>sub[N];
int ans[N];

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        if(sub[u].size() < sub[v].size()) swap(sub[u], sub[v]);
        for(auto col : sub[v]){
            sub[u].insert(col);
        }
    }
    ans[u] = sub[u].size();
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        sub[i].insert(c[i]);
    }

    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    for(int i=1;i<=n;i++){
        cout << ans[i] << " \n"[i==n];
    }

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