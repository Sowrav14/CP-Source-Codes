#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e18;


void solve(){

    int n, m, L, S, T;
    cin >> n >> m >> L >> S >> T;

    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    vector<vector<int>> cur(n+1), nxt(n+1);
    cur[1].push_back(0);

    for(int step=1; step<=L; step++){
        for(int i=1;i<=n;i++) nxt[i].clear();

        for(int u=1;u<=n;u++){
            if(cur[u].empty()) continue;
            for(auto &e : g[u]){
                int v = e.first;
                int w = e.second;
                for(int val : cur[u]){
                    int nv = val + w;
                    if(nv <= T){
                        nxt[v].push_back(nv);
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(!nxt[i].empty()){
                sort(nxt[i].begin(), nxt[i].end());
                nxt[i].erase(unique(nxt[i].begin(), nxt[i].end()), nxt[i].end());
            }
        }

        cur.swap(nxt);
    }

    vector<int> ans;
    for(int v=1;v<=n;v++){
        for(int val : cur[v]){
            if(val >= S && val <= T){
                ans.push_back(v);
                break;
            }
        }
    }

    if(ans.empty()){
        cout << endl;
        return;
    }

    sort(ans.begin(), ans.end());
    for(int v : ans) cout << v << " ";
    cout << endl;
}

signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
