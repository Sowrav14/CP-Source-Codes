#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<pair<int,int>>g[N];
int tim[N];
vector<int>leaf;

void dfs(int u, int p){
    if(g[u].size() == 1 and u != 1) leaf.push_back(tim[u]);

    int d = INT_MAX;
    for(auto c : g[u]){
        int v = c.first;
        int w = c.second;
        if(v == p) continue;
        d = min(d, w);
    }

    for(auto c : g[u]){
        int v = c.first;
        int w = c.second;
        if(v == p) continue;
        tim[v] = tim[u] + d + (w - d) * 2;
        dfs(v, u);
    }
}

void solve(){

    int n; cin >> n;
    for(int i=0;i<n+2;i++) g[i].clear();
    for(int i=0;i<n+2;i++) tim[i]= 0;
    leaf.clear();
    for(int i=2;i<=n;i++){
        int p, c; cin >> p >> c;
        g[p].push_back({i, c});
        g[i].push_back({p, c});
    }
    tim[1] = 0;
    dfs(1, 0);
    sort(leaf.begin(), leaf.end());
    // for(auto i : leaf) cout << i << " "; cout << endl;
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << upper_bound(leaf.begin(), leaf.end(), x) - leaf.begin() << endl;
    }
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}