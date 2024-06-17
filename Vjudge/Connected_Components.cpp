#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<set<int>> g;     // store the graph.
set<int> to_remove;     // track unvisited node.
vector<int>csz;

void bfs(int source){
    queue<int>q;
    q.push(source);
    to_remove.erase(source);        // similar work as visited array
    int sz = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        vector<int>adj;             // calculate adjacent node with 0 weight
        for(auto it : to_remove){   
            if(!g[u].count(it)){    // if i'th unvisited node is not adj.(weight = 0) to the current node
                adj.push_back(it);  // then connect it 
            }
        }
        for(auto it : adj){
            to_remove.erase(it);    // adjacent node (weight = 0) visited
            q.push(it);             // bfs work.
            sz++;
        }
    }
    csz.push_back(sz);
}


void solve(){

    int n,m; cin >> n >> m;
    g.resize(n+10);
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    // all nodes are unvisited initially.
    for(int i=1;i<=n;i++) to_remove.insert(i);
    int cc = 0;                                 // count of connected components

    for(int i=1;i<=n;i++){
        // if i'th node is unvisited then run a bfs from this and find the cc around it.
        if(to_remove.count(i)){
            cc++;
            bfs(i);
        }
    }

    cout << cc << endl;
    sort(csz.begin(), csz.end());
    for(auto i : csz){
        cout << i << " ";
    } cout << endl;

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