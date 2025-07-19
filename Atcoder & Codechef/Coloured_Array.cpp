#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct hopcorp {
    int left, right;
    vector<vector<int>> adj;
    vector<int> dist, mr, ml;
    hopcorp(int _left, int _right) : left(_left), right(_right), adj(left), dist(left), mr(right, -1), ml(left, -1) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }
    bool bfs() {
        queue<int> q;
        for(int i=0;i<left;i++) {
            if(ml[i] == -1) { dist[i] = 0; q.push(i); }
            else dist[i] = -1;
        }
        bool found = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                int u2 = mr[v];
                if(u2 < 0) found = 1;
                else if(dist[u2] < 0) {
                    dist[u2] = dist[u] + 1;
                    q.push(u2);
                }
            }
        }
        return found;
    }
    bool dfs(int u) {
        for(int v : adj[u]) {
            int u2 = mr[v];
            if(u2 < 0 || (dist[u2] == dist[u] + 1 && dfs(u2))) {
                ml[u] = v; mr[v] = u;
                return 1;
            }
        }
        dist[u] = -1;
        return 0;
    }
    int maxMatching() {
        int m = 0;
        while(bfs())
            for(int i=0;i<left;i++)
                if(ml[i] < 0 && dfs(i))
                    m++;
        return m;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++) cin >> a[i];
    vector<vector<int>> same(n+1), diff;
    for(int i=0;i<n;i++) {
        int x = a[2*i], y = a[2*i+1];
        if(x == y) same[x].push_back(i);
        else diff.push_back({i, x, y});
    }
    vector<char> vis1(n, 0), vis2(n+1, 0);
    int res = 0;
    for(int i=1;i<=n;i++) {
        if(!same[i].empty()) {
            int j = same[i].back();
            vis1[j] = 1;
            vis2[i] = 1;
            res++;
        }
    }
    hopcorp hop(n, n);
    for(auto &t : diff) {
        int i = t[0], x = t[1], y = t[2];
        if(vis1[i]) continue;
        if(!vis2[x]) hop.addEdge(i, x-1);
        if(!vis2[y] && y != x) hop.addEdge(i, y-1);
    }
    for(int v=1;v<=n;v++) {
        if(same[v].size() > 1) {
            for(int k=0;k<(int)same[v].size();k++) {
                int i = same[v][k];
                if(vis1[i]) continue;
                if(!vis2[v]) hop.addEdge(i, v-1);
            }
        }
    }
    int match = hop.maxMatching();
    int temp = 2 * res + 1 * match;
    int ans = 2 * n - temp;
    cout << ans << endl;
}

signed main() {
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) {
        solve();
    }
}