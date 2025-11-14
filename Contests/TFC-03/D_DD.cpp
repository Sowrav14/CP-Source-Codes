/*
 * @file Dijkstra.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-06-19
 * @copyright Copyright (c) 2024
 * @problem: https://cses.fi/problemset/task/1671
 * @approach: Dijkstras Algorithms.
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int,int>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3000 + 10;
const int inf = 1e18;
set<pii>g[N];
int a[N];
int n,m, T;

void Dijkstras(int s, vector<int>&d, vector<int>&cnt){
    d.resize(n+10, inf), cnt.resize(n+10, 0);
    vector<bool>vis(n+10, 0);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    d[s] = 0; cnt[s] = 1;

    while(!q.empty()){
        pii x = q.top();
        q.pop();
        int u = x.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto y : g[u]){
            int v = y.first;
            int w = y.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.push({d[v], v});
                cnt[v] = cnt[u];
            } else if(d[u] + w == d[v]){
                cnt[v] = cnt[v] + cnt[u];
            }
        }

    }
}
vector<int>d, c;

int dp[3010][3010];
int recur(int i, int t){
    if(i > n) {
        return 0;
    }
    if(dp[i][t] != -1) return dp[i][t];
    int sum = 0;
    if(t - d[i] >= 0 and d[i] != 0) sum = max({sum, a[i] + recur(i, t - d[i]), a[i] + recur(i+1, t - d[i])});
    sum = max(sum, recur(i+1, t));
    return dp[i][t] = sum;
}


void solve(){

    cin >> n >> m >> T;
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        if(u == v) continue;
        g[u].insert({v, 1});
        g[v].insert({u, 1});
    }

     // shortest distance and number of shortest path from source.
    Dijkstras(1, d, c);
    for(int i=1;i<=n;i++) d[i] < inf ? d[i] *= 2 : d[i] = 0;
    // for(int i=1;i<=n;i++){
    //     cout << d[i] << " "; 
    // } cout << endl;

    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=T;i++) cout << recur(1, i) << " ";
    cout << endl; 
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