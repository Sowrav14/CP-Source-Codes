#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

set<int> g[26];
vector<int>vis(26, 0);

int dfs(int u, int &loop, int &edge, int &t){
    vis[u] = t;
    for(auto v : g[u]){
        if(vis[v] == t){
            edge++;
            loop = 1;
        } else if(vis[v] == 0) {
            edge++;
            dfs(v, loop, edge, t);
        }
    }
}

void solve(){

    int n; cin >> n; 
    string a, b; cin >> a >> b;
    for(int i=0;i<n;i++){
        int u = a[i];
        int v = b[i];
        // if(u == v) continue;
        g[u - 'a'].insert(v - 'a');
    }

    int temp = -1;
    for(int i=0;i<26;i++){
        if(g[i].size() > 1) {
            cout << -1 << endl;
            return;
        }
        if(g[i].size() == 0) temp = i;
    }
    int ans = 0, t = 1;
    for(int i=0;i<26;i++){
        if(g[i].size() == 0) continue;
        if(vis[i]) continue;
        if(*g[i].begin() == i) continue;
        int loop = 0, edge = 0;
        dfs(i, loop, edge, t);
        t++;
        cout << i << " " << loop << " " << edge << endl;
        if(loop == 0) ans += edge;
        if(loop == 1){
            if(temp == -1){
                cout << -1 << endl;
                return;
            } else {
                ans += (edge + 1);
            }
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