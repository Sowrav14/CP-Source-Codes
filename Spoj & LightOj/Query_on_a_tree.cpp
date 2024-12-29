/**
 * @file Heavy Light Decomposition.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2024-10-14
 * @copyright Copyright (c) 2024
 * @problem: cses -> https://www.hackerrank.com/challenges/subtrees-and-paths/problem
 * @approach: Heavy Light Decomposition (HLD)
 * @explanation: https://cp-algorithms.com/graph/hld.html
 * @see_also: 
 *              - https://cses.fi/problemset/task/2134
 *              - https://cses.fi/problemset/task/1138
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int mxN = 1e4+5;
vector<int> adj[mxN];
int dp[mxN], depth[mxN], par[mxN];
int heavy[mxN], head[mxN], id[mxN];
int seg[10*mxN];
int N;

void update(int k, int x) {
    k += N; seg[k] = x; k >>= 1;
    while (k > 0) {
        seg[k] = max(seg[2 * k], seg[2 * k + 1]);
        k >>= 1;
    }
}

int query(int a, int b) {
    a += N, b += N;
    int s = 0;
    while (a <= b) {
        if (a & 1) {
            s = max(s, seg[a]);
            a++;
        }
        if (~b & 1) {
            s = max(s, seg[b]);
            b--;
        }
        a >>= 1, b >>= 1;
    }
    return s;
}

void dfs(int s, int p) {
    dp[s] = 1;
    int mx = 0;
    for (auto i : adj[s]) if (i != p) {
        par[i] = s;
        depth[i] = depth[s] + 1;
        dfs(i, s);
        dp[s] += dp[i];        
        if (dp[i] > mx) mx = dp[i], heavy[s] = i;
    }
}

int cnt = 0;
void hld(int s, int h) {
    head[s] = h;
    id[s] = ++cnt;
    // update(id[s] - 1, val[s]);
    if (heavy[s]) hld(heavy[s], h);
    for (auto i : adj[s]) {
        if (i != par[s] && i != heavy[s]) hld(i, i);
    }
}

int path(int x, int y){
    int ans = 0;
    while (head[x] != head[y]) {
        if (depth[head[x]] > depth[head[y]]) swap(x, y);
        ans = max(ans, query(id[head[y]] - 1, id[y] - 1));
        y = par[head[y]];
    }
    if(depth[x] > depth[y]) swap(x, y);
    ans = max(ans, query(id[x] - 1, id[y] - 1));
    return ans;
}

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

void add_edge(Edge i, int v = -1){
    int x, w;
    x = depth[i.u] > depth[i.v] ? i.u : i.v;
    w = v == -1 ? i.w : v;
    update(id[x] - 1, w);
}

void init(){
    cnt = 0;
    memset(head, 0, sizeof head);
    memset(id, 0, sizeof id);
    memset(par, 0, sizeof par);
    memset(depth, 0, sizeof depth);
    memset(heavy, 0, sizeof heavy);
    for(int i=1;i<=N;i++){
        adj[i].clear();
    }
}

void solve(){
    int n; cin >> n;
    N = n;
    init();
    vector<Edge>e;  
    for(int i=1;i<n;i++){
        int u, v, w; cin >> u >> v >> w;;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e.push_back(Edge(u, v, w));
    }

    dfs(1, 0);
    hld(1, 1);

    for(auto i : e){
        add_edge(i);
    }
    while (1) {
        string ty; cin >> ty;
        if(ty == "DONE"){
            return;
        } else if (ty == "CHANGE") {
            int id, v; cin >> id >> v;
            add_edge(e[id-1], v);
        } else {
            int u, v; cin >> u >> v;
            cout << (u == v ? 0 : path(u, v)) << '\n';
        }
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