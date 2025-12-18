#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Approach:
- For each case: read n,m.
- Read comma-separated processing times into val[0..n-1].
- Read m directed edges u v w (u->v).
- Find source (indeg==0) and sink (outdeg==0).
- Topological order using Kahn.
- DP longest path: dist[src]=val[src].
  For edge u->v with w: cand = dist[u] + w + val[v].
  If cand > dist[v]: dist[v]=cand; ways[v]=ways[u] (capped 2); parent[v] = (ways[u]==1 ? u : AMBIG)
  If cand == dist[v]: ways[v]+=ways[u] (cap 2); parent[v] = AMBIG
- If ways[sink] > 1 => output "z,M"
  Else reconstruct unique path from sink using parent (if any parent marked AMBIG -> print M)
*/

const int AMBIG = -2;

void solve_case(){
    int n, m;
    if(!(cin >> n >> m)) return;

    string s; cin >> s;
    vector<int> val;
    val.reserve(n);
    string cur = "";
    for(char ch : s){
        if(ch == ','){
            if(!cur.empty()){
                val.push_back(stoll(cur));
                cur.clear();
            }
        } else cur.push_back(ch);
    }
    if(!cur.empty()) val.push_back(stoll(cur));

    vector<vector<pair<int,int>>> g(n);
    vector<int> indeg(n,0), outdeg(n,0);
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        indeg[v]++; outdeg[u]++;
    }

    int src = -1, sink = -1;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0) src = i;
        if(outdeg[i] == 0) sink = i;
    }

    if(src == -1 || sink == -1){
        cout << "0,M" << endl;
        return;
    }

    // Kahn topo
    queue<int> q;
    vector<int> indeg_copy = indeg;
    for(int i=0;i<n;i++) if(indeg_copy[i]==0) q.push(i);
    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto &e : g[u]){
            int v = e.first;
            indeg_copy[v]--;
            if(indeg_copy[v]==0) q.push(v);
        }
    }

    const long long NEG = LLONG_MIN / 4;
    vector<long long> dist(n, NEG);
    vector<int> ways(n, 0); // capped at 2
    vector<int> parent(n, -3); // -3 unset, -1 source sentinel, AMBIG ambiguous, >=0 parent index

    dist[src] = val[src];
    ways[src] = 1;
    parent[src] = -1;

    for(int u : topo){
        if(dist[u] == NEG) continue;
        for(auto &e : g[u]){
            int v = e.first; int w = e.second;
            long long cand = dist[u] + w + val[v];
            if(cand > dist[v]){
                dist[v] = cand;
                ways[v] = min(2LL, (long long)ways[u]);
                parent[v] = (ways[u] == 1 ? u : AMBIG);
            } else if(cand == dist[v]){
                ways[v] = min(2ll, ways[v] + ways[u]);
                parent[v] = AMBIG;
            }
        }
    }

    long long z = dist[sink];
    if(z == NEG){
        cout << "0,M" << endl;
        return;
    }

    if(ways[sink] > 1){
        cout << z << ",M" << endl;
        return;
    }

    // unique path: reconstruct, but ensure no ambiguous parent encountered
    vector<int> path;
    int curv = sink;
    path.push_back(curv);
    while(parent[curv] != -1){
        int p = parent[curv];
        if(p == AMBIG || p == -3){
            cout << z << ",M" << endl;
            return;
        }
        curv = p;
        path.push_back(curv);
    }
    reverse(path.begin(), path.end());
    cout << z;
    for(size_t i=0;i<path.size();i++) cout << "," << path[i];
    cout << endl;
}

signed main(){
    Fast_IO()
    int n,m;
    while(cin >> n >> m){
        // put back n,m into stream for solve_case to read
        // simpler: call a small wrapper using known n,m
        // read the rest of this case here directly (to avoid double-read)
        string s; cin >> s;
        vector<int> val;
        val.reserve(n);
        string cur = "";
        for(char ch : s){
            if(ch == ','){
                if(!cur.empty()){ val.push_back(stoll(cur)); cur.clear(); }
            } else cur.push_back(ch);
        }
        if(!cur.empty()) val.push_back(stoll(cur));

        vector<vector<pair<int,int>>> g(n);
        vector<int> indeg(n,0), outdeg(n,0);
        for(int i=0;i<m;i++){
            int u,v,w; cin >> u >> v >> w;
            g[u].push_back({v,w});
            indeg[v]++; outdeg[u]++;
        }

        int src = -1, sink = -1;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0) src = i;
            if(outdeg[i] == 0) sink = i;
        }
        if(src == -1 || sink == -1){
            cout << "0,M" << endl;
            continue;
        }

        queue<int> q;
        vector<int> indeg_copy = indeg;
        for(int i=0;i<n;i++) if(indeg_copy[i]==0) q.push(i);
        vector<int> topo;
        while(!q.empty()){
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(auto &e : g[u]){
                int v = e.first;
                indeg_copy[v]--;
                if(indeg_copy[v]==0) q.push(v);
            }
        }

        const long long NEG = LLONG_MIN / 4;
        vector<long long> dist(n, NEG);
        vector<int> ways(n, 0);
        vector<int> parent(n, -3);
        dist[src] = val[src];
        ways[src] = 1;
        parent[src] = -1;

        for(int u : topo){
            if(dist[u] == NEG) continue;
            for(auto &e : g[u]){
                int v = e.first; int w = e.second;
                long long cand = dist[u] + w + val[v];
                if(cand > dist[v]){
                    dist[v] = cand;
                    ways[v] = min(2LL, (long long)ways[u]);
                    parent[v] = (ways[u] == 1 ? u : AMBIG);
                } else if(cand == dist[v]){
                    ways[v] = min(2ll, ways[v] + ways[u]);
                    parent[v] = AMBIG;
                }
            }
        }

        long long z = dist[sink];
        if(z == NEG){
            cout << "0,M" << endl;
            continue;
        }
        if(ways[sink] > 1){
            cout << z << ",M" << endl;
            continue;
        }
        vector<int> path;
        int curv = sink;
        path.push_back(curv);
        bool amb = false;
        while(parent[curv] != -1){
            int p = parent[curv];
            if(p == AMBIG || p == -3){ amb = true; break; }
            curv = p;
            path.push_back(curv);
        }
        if(amb){
            cout << z << ",M" << endl;
            continue;
        }
        reverse(path.begin(), path.end());
        cout << z;
        for(int x : path) cout << "," << x;
        cout << endl;
    }

    return 0;
}
