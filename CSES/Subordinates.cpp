#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
vector<int>g[N];
int vis[N], ans[N];

void dfs(int u){
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
            ans[u] += ans[v];
        }
    }
}


void solve(){

    int n; cin >> n;
    for(int i=2;i<=n;i++){
        int j; cin >> j;
        g[i].push_back(j);
        g[j].push_back(i);
        ans[i] = 1;
    }
    ans[1] = 1;

    dfs(1);

    for(int i=1;i<=n;i++) cout << ans[i]-1 << " "; cout << endl;

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