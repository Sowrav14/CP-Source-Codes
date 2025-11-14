#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int> g[4];
int vis[4];
int ans = 0;

void dfs(int u, int v, int d){
    // cout << u << " " << g[u].size() << " " << d << endl;
    if(u == v) {
        // cout << "got" << endl;
        ans = max(ans, d);
        // cout << "ans " << ans << endl;
        // return;
    }
    vis[u]++;
    for(auto c : g[u]){
        if(vis[c] < 2) dfs(c, v, d + 1);
    }
}

void solve(){

    string dir;
    int q;
    while(getline(cin, dir)){
        if(dir.size() < 3){
            q = stoi(dir);
            break;
        } else {
            int u = dir[0] - 'A';
            int v = dir[5] - 'A';
            if(dir[2] == '-'){
                g[u].push_back(v);
            } else {
                g[v].push_back(u);
            }
        }
    }

    while(q--){
        char x, y; cin >> x >> y;
        int xx = x - 'A', yy = y - 'A';
        ans = 0;
        for(int i=0;i<4;i++) vis[i] = 0;
        dfs(xx, yy, 0);
        // cout << ans << endl;
        if(ans == 0){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
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