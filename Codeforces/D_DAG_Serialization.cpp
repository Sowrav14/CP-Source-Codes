#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// logical order.
// (0, 0) (1, 1) (1, 0) (0, 1) (0, 0)
int type[N], result[N];
vector<int> g[N];
int indeg[N];
queue<int> q[2][2];
bool flag;
int cur;
vector<int>ans;

void topSort(int i, int j){
    // cout << i << " " << j << " " << cur << endl;
    // cout << q[i][j].size() << endl;
    while(!q[i][j].empty()){
        int u = q[i][j].front();
        q[i][j].pop();
        if(cur ^ i != j) flag = false;
        ans.push_back(u);
        cur = i;

        for(auto v : g[u]){
            --indeg[v];
            if(indeg[v] == 0){
                q[type[v]][result[v]].push(v);
            }
        }
    }
}

void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        string t, r; cin >> t >> r;
        type[i] = (t[0] == 's');
        result[i] = (r[0] == 't');
    }

    int m; cin >> m;
    for(int i=1;i<=m;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    for(int i=1;i<=n;i++){
        if(indeg[i] == 0) q[type[i]][result[i]].push(i);
    }
    flag = true; cur = 0;
    topSort(0, 0);
    topSort(1, 1);
    topSort(1, 0);
    topSort(0, 1);
    topSort(0, 0);
    // cout << flag << endl;
    if(ans.size() != n) flag = false;

    if(flag){
        for(int i=0;i<n;i++) cout << ans[i] << " \n"[i == n-1];
    } else {
        cout << -1 << endl;
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