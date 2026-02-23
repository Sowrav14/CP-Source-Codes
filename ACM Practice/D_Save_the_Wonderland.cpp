#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 5e5 + 10;
const int inf = 1e8;

vector<int> g[N];
pair<int,int> d[N];
int vis[N];
int tot = 0;

void dfs(int u, int p, int k){

    int mn = inf, mx = 0;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u, k);
        mn = min(mn, d[v].first);
        mx = max(mx, d[v].second);
    }

    // if i am guarded..
    // if my other subtree are guarded
    if(mn >= 0){
        if(p == 0){
            tot++;
        }
    }

    if(mx == k){
//        cout << "placing guard " << u << endl;
        tot++;
        d[u] = {1, -inf};
    } else if(mn + mx <= k){
        d[u] = {mn + 1, -inf};
    } else {
        d[u] = {mn+1, mx + 1};
    }

}


void solve(){

    int n, k; cin >> n >> k;
    for(int i=1;i<=n;i++){
        g[i].clear();
        d[i] = {1, 0};
    }
    for(int i=1;i<n;i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int l = 0, r = inf;
    int ans = inf;
    while(l <= r){
        int m = (l + r) / 2;
        tot = 0;
        for(int it=0;it<=n;it++) d[it] = {1, -inf};
//        cout << m << endl;
        dfs(1, 0, m);
        // if(d[1].second >= 0) tot++;
        if(tot <= k){
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << endl;
//    cout << tot << endl;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int _t=1;_t<=t;_t++){
        solve();
    }
}